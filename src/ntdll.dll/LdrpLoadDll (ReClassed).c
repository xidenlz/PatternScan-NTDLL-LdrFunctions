__int64 LdrpLoadDll(__int64 lpModuleName, int dwFlags, unsigned int dwCharacteristics, __int64 *lpBaseAddress)
{
  unsigned int dwModuleNameLength; // [rsp+40h] [rbp-C0h] BYREF
  unsigned int dwAllocatedBufferSize; // [rsp+48h] [rbp-B8h] BYREF
  int dwLastError; // [rsp+50h] [rbp-B0h] BYREF
  __int16 *lpProcessedModuleName; // [rsp+58h] [rbp-A8h]
  __int16 lpModuleNameBuffer[128]; // [rsp+60h] [rbp-A0h] BYREF

  dwModuleNameLength = dwCharacteristics;
  LdrpLogDllState(0LL, lpModuleName, 5288LL);
  dwAllocatedBufferSize = 0x1000000;
  lpProcessedModuleName = lpModuleNameBuffer;
  lpModuleNameBuffer[0] = 0;
  dwLastError = LdrpPreprocessDllName(lpModuleName, &dwAllocatedBufferSize, 0LL, &dwModuleNameLength);
  if ((dwLastError & 0x80000000) == 0)
    LdrpLoadDllInternal((__int64)&dwAllocatedBufferSize, dwFlags, dwModuleNameLength, 4, 0LL, 0LL, lpBaseAddress, (int *)&dwLastError);
  if (lpModuleNameBuffer != lpProcessedModuleName)
    NtdllpFreeStringRoutine();
  dwAllocatedBufferSize = 0x1000000;
  lpProcessedModuleName = lpModuleNameBuffer;
  lpModuleNameBuffer[0] = 0;
  LdrpLogDllState(0LL, lpModuleName, 5289LL);
  return dwLastError;
}
