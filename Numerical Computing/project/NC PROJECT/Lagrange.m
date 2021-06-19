function Pn = Lagrange()
    x = input('Enter Co-ordinates values in brackets, in the form [x x x ...]:');
    y = input('Enter Co-ordinates values in brackets, in the form [y y y ...]:');
    Pn = 0;
    a=input('Enter value of "x": ');
    
    for i = 1:length(x)
        u=1;
        l=1;

        for j = 1:length(x)
            if j ~= i
                u = u * (a-x(j));
                l = l * (x(i)-x(j));
            end
        end

        Pn=Pn+u/l*y(i);
    end
    
    disp(Pn);
end
