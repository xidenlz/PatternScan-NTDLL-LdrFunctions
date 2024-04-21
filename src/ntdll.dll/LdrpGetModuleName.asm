.text:00000000000010E8 ; __unwind { // __GSHandlerCheck
.text:00000000000010E8                 mov     [rsp-8+arg_18], rbx ; LdrpGetModuleName 48 89 5C 24 20 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 90 FE FF FF
.text:00000000000010ED                 push    rbp
.text:00000000000010EE                 push    rsi
.text:00000000000010EF                 push    rdi
.text:00000000000010F0                 push    r12
.text:00000000000010F2                 push    r13
.text:00000000000010F4                 push    r14
.text:00000000000010F6                 push    r15
.text:00000000000010F8                 lea     rbp, [rsp-170h]
.text:0000000000001100                 sub     rsp, 270h
.text:0000000000001107                 mov     rax, cs:__security_cookie
.text:000000000000110E                 xor     rax, rsp
.text:0000000000001111                 mov     [rbp+1A0h+var_40], rax
.text:0000000000001118                 movzx   ebx, word ptr [rdx]
.text:000000000000111B                 mov     eax, 200h
.text:0000000000001120                 mov     edi, r9d
.text:0000000000001123                 mov     r14, r8
.text:0000000000001126                 mov     r15, rcx
.text:0000000000001129                 cmp     bx, ax
.text:000000000000112C                 jnb     loc_A7604
