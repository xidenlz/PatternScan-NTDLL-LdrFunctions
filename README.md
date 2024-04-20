### PatternScan-NTDLL-LdrFunctions
This repository hosts code for a pattern scanning utility designed to locate specific functions within the **ntdll.dll** library of the Windows operating system. Specifically, it searches for the addresses of [LdrLoadDll](https://malapi.io/winapi/LdrLoadDll) and **LdrpLoadDllInternal**, which are core functions responsible for loading dynamic-link libraries (DLLs) within the Windows kernel.

The utility utilizes the FindPattern function, which iterates through the memory space of **ntdll.dll** using a provided pattern and mask to identify the target function signatures. By employing this method, developers and researchers can dynamically locate these critical functions, facilitating various analysis tasks and enabling more flexible user-mode interactions through techniques like [GetProcAddress](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress).

Additionally, the repository includes research findings on the reverse engineering and reclassing of these functions using [IDA Pro](https://hex-rays.com/ida-pro/). This research provides insights into the internal workings and structures of **LdrLoadDll** and **LdrpLoadDllInternal**, aiding in further understanding and utilization of these functions within the Windows kernel.
You can find the reversed and reclassed functions [here](https://github.com/byte-zone/ByteZone_Injector/tree/main/Helpers/ntdll).

### Results 
- ```LdrLoadDll found at address: 0x7ff951abd771```
- ```LdrpLoadDllInternal found at address: 0x7ff951abff67```
- ```LdrpLoadDll found at address: 0x7ff951a15bcc```
> [!NOTE]
> **Tested on Windows 10 2H22**
