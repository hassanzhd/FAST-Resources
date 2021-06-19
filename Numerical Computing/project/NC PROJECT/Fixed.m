function Fixed()
    syms f(x)
    Fun=input('Enter function: ','s');
    f(x)= str2sym(Fun);
    
    n=input('Enter value of n: ');
    x=input('Enter value of x: '); 
    i=1;
    y=f(x);
    
    if y==x 
    fprintf('The fixed point is %f', y);
    end
    
    fprintf("n       x            y");

    
    while abs(x-y)>1.0E-5 && i+1<=n
    i=i+1;
    x=y;
    y=f(x);
    fprintf("%d        %.6f        %.6f    \n",i,x,y);
    end
end    