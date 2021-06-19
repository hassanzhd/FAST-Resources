function Newton()
    clear
    syms x z s k;
    Fun=input('Enter function: ','s');
    in = str2sym(Fun);
    
    syms f(x)
    f(x) = in;
    f1 = diff(f,x);
    
    a=input('Enter value of a: ');
    b=input('Enter value of b: ');
    
    po=a;
    fprintf("n     po             p1\n");
    
    for j=1:100
        p1=po-(f(po)/f1(po));
        if  (abs(p1-po))>1.0E-4
            k = po;
            po=p1;
            fprintf("%d     %f            %f ",j ,k, p1);
            fprintf('\n');
        else
            fprintf("%d     %f             %f ",j ,k, p1);
            return
        end
    end
    
end