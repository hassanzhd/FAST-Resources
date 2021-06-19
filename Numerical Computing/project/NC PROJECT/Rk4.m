function Rk4()
    str = input('Enter function in terms of x and y: ','s')  ;
    F_xy = inline(str,'x', 'y') ;
    h = input('Enter value of h : ');                  
    ini = input('Enter value of x : ');
    max = input('Maximum value of x : ');
    
    x = ini:h:max;                                     
    y = zeros(1,length(x)); 
    y(1) = 5;                                         
    
    for i=1:(length(x)-1)                              
        k_1 = F_xy(x(i),y(i));
        k_2 = F_xy(x(i)+0.5*h,y(i)+0.5*h*k_1);
        k_3 = F_xy((x(i)+0.5*h),(y(i)+0.5*h*k_2));
        k_4 = F_xy((x(i)+h),(y(i)+k_3*h));
        y(i+1) = y(i) + (1/6)*(k_1+2*k_2+2*k_3+k_4)*h;  
    end
    
end