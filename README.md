### ملخص 
يقدم هذا البحث استكشافًا عميقًا لآليات تحميل ملفات الارتباط الديناميكي (DLL) في ntdll.dll، مكتبة نظام التشغيل ويندوز الأساسية. يركز البحث على الدوال الداخلية غير الموثقة، ويستخدم تقنيات مسح الأنماط المتقدمة لتحديد عناوينها بدقة.
### مقدمة 
تُعد ملفات DLL مكونات حيوية لنظام ويندوز، حيث توفر وظائف قابلة لإعادة الاستخدام عبر التطبيقات المختلفة. تُشرف مجموعة من الدوال الداخلية على تحميل هذه الملفات، وتقع هذه الدوال في ntdll.dll.
### التحديات 
تواجه عملية استدعاء هذه الدوال الداخلية من وضع المستخدم (user mode) تحديات كبيرة، حيث لا توفر Microsoft وثائق رسمية حولها، للتغلب على هذه التحديات، قمت قمت بتطوير ماسح الأنماط المتقدمة. تُتيح هذه الاداة تحديد عناوين الدوال من خلال تحليل تسلسلات البايتات المميزة المرتبطة بها




<p align="center">
  <img src="https://github.com/Mes2d/PatternScan-NTDLL-LdrFunctions/blob/main/src/images/image.png">
</p>




### العناوين 
1. **LdrpReadMemory:** ```48 83 C4 ? 5B C3 CC CC CC CC CC CC CC CC CC CC CC CC CC CC CC CC CC 48 8B C4 // Wildcards```
2. **LdrpGetModuleName:** ```48 89 5C 24 20 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 90 FE FF FF```
3. **LdrUnloadDll:** ```48 8B C4 48 89 58 08 48 89 70 20 57```
4. LdrpFindLoadedDllByHandle: ```48 89 5C 24 08 48 89 74 24 10 48 89 7C 24 18 41 56 48 83 EC 20 33 DB 49 8B F8 4C 8B F2```
5. **LdrpLoadDll:** ```40 55 53 56 57 41 56 41 57 48 8D 6C 24 88```
### الختام 
قمت بتطوير هذة الأداة لأنني أعمل على مشروع ضخم في تقنيات حقن ملفات الارتباط الديناميكي وأحتاج لاستدعاء هذة الدوال، تستطيع أن تعرف أكثر عن المشروع [هنا](https://github.com/byte-zone/ByteZone_Injector)
### موارد إضافية 
- تم استخدام [IDA Pro](https://hex-rays.com/ida-pro/) لتفكيك ntdll.dll في هذا البحث
- نتائج [البحث](https://github.com/Mes2d/PatternScan-NTDLL-LdrFunctions/tree/main/src/ntdll.dll)
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
