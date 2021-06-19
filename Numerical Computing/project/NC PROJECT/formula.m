function y = formula(x,p)

    y = x(1)+ p*x(2)+ ((p*(p-1))/factorial(2))*x(3) + ((p*(p-1)*(p-2))/factorial(3))*x(4) + ((p*(p-1)*(p-2)*(p-3))/factorial(4))*x(5) ...
        + ((p*(p-1)*(p-2)*(p-3)*(p-4))/factorial(5))*x(6) + ((p*(p-1)*(p-2)*(p-3)*(p-4)*(p-5))/factorial(6))*x(7) + ...
        ((p*(p-1)*(p-2)*(p-3)*(p-4)*(p-5)*(p-6))/factorial(7))*x(8) + ((p*(p-1)*(p-2)*(p-3)*(p-4)*(p-5)*(p-6)*(p-7))/factorial(8))*x(9);
    
end
