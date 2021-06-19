fprintf(" 1)Bisection Method\n 2)Fixed Method\n 3)Newton Method\n 4)Reguli Falsi Method\n 5)Secant Method\n 6)Lagrange Method\n 7)SDT and DDT Methods\n 8)Central Difference Method\n 9)Euler Method\n 10)Huen Method\n 11)4RK Method\n 12)Jacobi Method\n 13)Seidal Method\n");
choice=input('\n\nChoose A Method : ');

switch choice
    case 1
        Bisection()
    case 2
        Fixed()
    case 3
        Newton()
    case 4
        ReguliFalsi()
    case 5
        Secant()
    case 6
        Lagrange()
    case 7
        SDT_DDT()
    case 8
        central_diff()
    case 9
        Euler()
    case 10
        huen()
    case 11
        RK4()
    case 12
        jacobi()
    case 13
        seidal()
    otherwise
        disp('Please Select Correct Option')
end