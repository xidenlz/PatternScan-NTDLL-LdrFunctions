#include <Windows.h>
#include <Psapi.h>
#include <iostream>
#include <vector>


uintptr_t FindPattern(const char* module, const char* pattern, const char* mask) {
    MODULEINFO moduleInfo = { 0 };
    HMODULE hModule = GetModuleHandleA(module);
    if (!hModule)
        return 0;

    GetModuleInformation(GetCurrentProcess(), hModule, &moduleInfo, sizeof(MODULEINFO));
    uintptr_t moduleBase = reinterpret_cast<uintptr_t>(moduleInfo.lpBaseOfDll);
    uintptr_t moduleEnd = moduleBase + moduleInfo.SizeOfImage;

    const size_t patternLength = strlen(mask);
    const BYTE* patternBytes = reinterpret_cast<const BYTE*>(pattern);

    for (uintptr_t i = moduleBase; i < moduleEnd - patternLength; ++i) {
        bool found = true;
        for (size_t j = 0; j < patternLength; ++j) {
            if (mask[j] != '?' && patternBytes[j] != *reinterpret_cast<const BYTE*>(i + j)) {
                found = false;
                break;
            }
        }
        if (found)
            return i;
    }

    return 0;
}

int main() {

    const char* LdrLoadDll = "\x4C\x8D\x05\x18\x4F\x08\x00"; // 4C 8D 05 18 4F 08 00 does not accepts wilcards I'm not sure
    const char* LdrLoadDll_Mask = "xxxxxxx";

    const char* LdrpLoadDllInternal = "\x8B\x03\x89\x44\x24\x28"; // 8B 03 89 44 24 28 does not accepts wilcards I'm not sure
    const char* LdrpLoadDllInternal_Mask = "xxxxxx";

    /* LdrpLoadDll */
    const char* LdrpLoadDll = "\x40\x55\x53\x56\x57\x41\x56\x41\x57\x48\x8D\x6C\x24\x88"; // 40 55 53 56 57 41 56 41 57 48 8D 6C 24 88 does not accepts wilcards I'm not sure
    const char* LdrpLoadDll_Mask = "xxxxxx";


    /* LdrLoad DLL*/
    uintptr_t LdrLoadDll_Addr = FindPattern("ntdll.dll", LdrLoadDll, LdrLoadDll_Mask);

    /* LdrpLoadInternalDll */
    uintptr_t LdrpLoadDllInternal_Addr = FindPattern("ntdll.dll", LdrpLoadDllInternal, LdrpLoadDllInternal_Mask);


    /* LdrpLoadDll */
    uintptr_t LdrpLoadDll_Addr = FindPattern("ntdll.dll", LdrpLoadDll, LdrpLoadDll_Mask);

    if (LdrpLoadDll_Addr)
    {
        std::cout << "LdrpLoadDll found at address: 0x" << std::hex << LdrpLoadDll_Addr << std::endl;
    }
    else
    {
        std::cout << "LdrpLoadDll not found." << std::endl;
    }

    if (LdrLoadDll_Addr) {
        std::cout << "LdrLoadDll found at address: 0x" << std::hex << LdrLoadDll_Addr << std::endl;
    }
    else {
        std::cout << "LdrLoadDll addr not found." << std::endl;
    }

    if (LdrpLoadDllInternal_Addr) {
        std::cout << "LdrpLoadDllInternal found at address: 0x" << std::hex << LdrpLoadDllInternal_Addr << std::endl;
    }
    else {
        std::cout << "LdrpLoadDllInternal not found." << std::endl;
    }

    system("pause");
}
