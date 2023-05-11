.assembly GoodProgram {}

.method static public void main() il managed {
.entrypoint
.maxstack 8

.locals init ([0] int32 x)
ldc.i4 6
stloc.0

.locals init ([1] int32 y)
ldc.i4 100
stloc.1

.locals init ([2] int32 z)

ldloc.1
ldloc.0
div
stloc.2

ldloc.2
call void [mscorlib]System.Console::WriteLine(int32)

ret
}
