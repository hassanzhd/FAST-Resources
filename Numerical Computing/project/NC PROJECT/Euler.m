function Euler()
    str = input('Enter equation in terms of x and y: ','s')  ;
    
    f=inline(str,'x', 'y' , 'i') ;
    h=input('Value of h : ');
    initial=input('Value of x : ');
    maximum=input('Maximum value of x : ');
    
    x=initial:h:maximum; 
    y=zeros(size(x));  
    y(1)=1; 
    n = numel(y);

    for i=1:n-1
        p = feval(f,x,y,i) ;    
        y(i+1) = y(i) + h * p;
    end
    
end