int GetModuleNameFromAddress(__int64 *lpBaseAddress, __int64 lpBuffer, __int64 dwBufferSize, int bFullPath)
{
  unsigned __int16 bufferSize; // bx
  int result; // eax
  char *lpEnd; // rcx
  const wchar_t *systemRoot; // rax
  __int64 i; // rcx
  size_t rootLength; // rdi
  __int64 lpProcess; // rcx
  unsigned __int16 machineList[8]; // [rsp+20h] [rbp-E0h] BYREF
  STRING destinationString; // [rsp+30h] [rbp-D0h] BYREF
  UNICODE_STRING sourceString; // [rsp+40h] [rbp-C0h] BYREF
  wchar_t tempBuffer[264]; // [rsp+50h] [rbp-B0h] BYREF

  bufferSize = *(_WORD *)lpBuffer;
  if ( *(_WORD *)lpBuffer >= 0x200u )
    bufferSize = 512;
  result = LdrpReadMemory((__int64)lpBaseAddress, *(_QWORD *)(lpBuffer + 8), (__int64)tempBuffer, bufferSize);
  if ( result >= 0 )
  {
    tempBuffer[256] = 0;
    if ( !bFullPath )
      goto LABEL_5;
    systemRoot = (const wchar_t *)RtlGetNtSystemRoot();
    i = -1LL;
    do
      ++i;
    while ( systemRoot[i] );
    if ( !i )
      return -1073741595;
    rootLength = i - 1;
    if ( systemRoot[i - 1] != 92 )
      rootLength = i;
    if ( wcsnicmp(tempBuffer, systemRoot, rootLength) || wcsnicmp(&tempBuffer[rootLength], L"\\system32", 9uLL) )
      goto LABEL_5;
    if ( rootLength + 16 >= 0x101 )
      return -1073741595;
    lpProcess = *lpBaseAddress;
    if ( !*lpBaseAddress )
      lpProcess = -1LL;
    if ( (int)RtlWow64GetProcessMachines(lpProcess, machineList, 0LL) >= 0
      && (sourceString.Buffer = tempBuffer,
          sourceString.MaximumLength = bufferSize,
          sourceString.Length = bufferSize,
          *(_DWORD *)(&destinationString.MaximumLength + 1) = *(_DWORD *)(&sourceString.MaximumLength + 1),
          destinationString.Buffer = (char *)&tempBuffer[rootLength],
          destinationString.Length = -2 * rootLength + bufferSize,
          destinationString.MaximumLength = destinationString.Length,
          (int)RtlReplaceSystemDirectoryInPath(&destinationString, 1LL, machineList[0], 0LL) >= 0) )
    {
LABEL_5:
      sourceString.MaximumLength = bufferSize;
      sourceString.Buffer = tempBuffer;
      sourceString.Length = bufferSize;
      destinationString.Buffer = (char *)(dwBufferSize + 40);
      *(_DWORD *)&destinationString.Length = 0x1000000;
      result = RtlUnicodeStringToAnsiString(&destinationString, &sourceString, 0);
      if ( result >= 0 )
      {
        lpEnd = &destinationString.Buffer[destinationString.Length];
        while ( lpEnd > destinationString.Buffer )
        {
          if ( *--lpEnd == 92 )
          {
            LOWORD(lpEnd) = (_WORD)lpEnd + 1;
            break;
          }
        }
        *(_WORD *)(dwBufferSize + 38) = (_WORD)lpEnd - LOWORD(destinationString.Buffer);
        return 0;
      }
    }
    else
    {
      return -1073741595;
    }
  }
  return result;
}
