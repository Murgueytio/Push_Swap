@echo off
setlocal EnableDelayedExpansion

:: Colors for output
set "RED=[91m"
set "GREEN=[92m"
set "YELLOW=[93m"
set "NC=[0m"

:: Function for testing and counting operations
:test_numbers
set "args=%*"
for /f %%i in ('push_swap.exe %args% ^| find /c /v ""') do set result=%%i
for /f %%i in ('push_swap.exe %args% ^| checker_OS.exe %args%') do set sorted=%%i

echo %YELLOW%Test [%args%]: %NC%
if "%sorted%"=="OK" (
    echo %GREEN%OK%NC% (!result! moves^)
) else (
    echo %RED%KO%NC%
)
exit /b

:: Basic cases
echo === Casos básicos ===
call :test_numbers 2 1
call :test_numbers 1 2 3
call :test_numbers 2 1 3
call :test_numbers 3 2 1
call :test_numbers 3 1 2

:: Cases with 5 numbers
echo.
echo === Casos con 5 números ===
call :test_numbers 1 5 2 4 3
call :test_numbers 5 4 3 2 1
call :test_numbers 2 3 4 5 1

:: Cases with negative numbers
echo.
echo === Casos con negativos ===
call :test_numbers -1 5 -2 4 -3
call :test_numbers -5 -4 -3 -2 -1
call :test_numbers 2 -3 4 -5 1

:: Borderline cases
echo.
echo === Casos límite ===
call :test_numbers 2147483647 -2147483648 0
call :test_numbers 42 2147483647 -2147483648

:: Error cases (should display "Error")
echo.
echo === Casos de error ===
echo|set /p="Número duplicado: "
push_swap.exe 1 2 2 3

echo|set /p="Número fuera de rango: "
push_swap.exe 1 2 2147483648 3

echo|set /p="Argumento no numérico: "
push_swap.exe 1 2 "abc" 3

:: Performance test
echo.
echo === Tests de rendimiento ===
echo 100 números aleatorios:
:: Generar números aleatorios del 1 al 100
set "nums="
for /l %%i in (1,1,100) do set "nums=!nums! %%i"
call :test_numbers %nums%

echo.
echo 500 números aleatorios:
:: Generar números aleatorios del 1 al 500
set "nums="
for /l %%i in (1,1,500) do set "nums=!nums! %%i"
call :test_numbers %nums% 
