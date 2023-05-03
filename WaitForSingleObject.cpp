HANDLE hWaitEvent;
HANDLE hWaitEventMain;
//HANDLE hWaitMutex;
//
void PauseThreadProc(void *vPauseTime )
{
	int *iPause = (int*) vPauseTime;
	WaitForSingleObject( hWaitEvent, *iPause );
	//ReleaseMutex(hWaitMutex);
	SetEvent(hWaitEventMain);
	// exlicitly close the thread handle
	_endthread();
}


// SetEvent(hWaitEvent); gelirse waitten vaz gecer
class WaitSome
{
	public :
	HANDLE hThread;

	WaitSome(int iPauseTime)
	{
		//hWaitMutex = CreateMutex (NULL, FALSE, NULL);
		hWaitEventMain = CreateEvent(NULL, FALSE, FALSE, L"PauseThreadMain");
		hWaitEvent = CreateEvent(NULL, FALSE, FALSE, L"PauseThread");
		ResetEvent(hWaitEvent);
		hThread = (HANDLE) _beginthread( PauseThreadProc, 0, &iPauseTime );
		ResetEvent(hWaitEventMain);
		WaitForSingleObject( hWaitEventMain, iPauseTime );
	};

	~WaitSome()
	{
		CloseHandle(hWaitEvent);
		CloseHandle(hWaitEventMain);
		//CloseHandle(hWaitMutex);
		//CloseHandle(hThread); // bu gerekli degil
	}; 

};

