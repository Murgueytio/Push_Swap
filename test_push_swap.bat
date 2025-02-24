@echo off
setlocal EnableDelayedExpansion
chcp 65001 > nul

echo === PRUEBAS BASICAS ===
echo.
echo Test con 2 números [2 1]:
for /f %%i in ('push_swap.exe 2 1 ^| find /c /v ""') do echo Operaciones: %%i (max 3)
echo.

echo Test con 3 números [3 2 1]:
for /f %%i in ('push_swap.exe 3 2 1 ^| find /c /v ""') do echo Operaciones: %%i (max 3)
echo.

echo Test con 5 números [5 4 3 2 1]:
for /f %%i in ('push_swap.exe 5 4 3 2 1 ^| find /c /v ""') do echo Operaciones: %%i (max 12)
echo.

echo === PRUEBAS CON NEGATIVOS ===
echo.
echo Test [-1 5 -2 4 -3]:
for /f %%i in ('push_swap.exe -1 5 -2 4 -3 ^| find /c /v ""') do echo Operaciones: %%i (max 12)
echo.

echo === PRUEBAS DE ERROR ===
echo.
echo Test duplicado [1 2 2 3]:
push_swap.exe 1 2 2 3
echo.

echo Test no numérico [1 a 3]:
push_swap.exe 1 a 3
echo.

echo Test fuera de rango [2147483648]:
push_swap.exe 2147483648
echo.

echo === PRUEBA DE RENDIMIENTO ===
echo.
echo Test con 100 números ordenados inversamente:
set "nums="
for /l %%i in (100,-1,1) do set "nums=!nums! %%i"
for /f %%i in ('push_swap.exe !nums! ^| find /c /v ""') do (
    echo Operaciones: %%i (max 700)
    if %%i leq 700 (
        echo RESULTADO: OK
    ) else (
        echo RESULTADO: KO - Demasiadas operaciones
    )
)
