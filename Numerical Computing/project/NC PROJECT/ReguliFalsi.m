function ReguliFalsi()
    syms f(x)
    func=input('Enter function: ','s');
    f(x)= str2sym(func);
    a=input('Enter the value of a','s');
    b=input('Enter the value of b','s');
    if f(a)*f(b)>0
     fprintf('NO ROOTS EXIST');
     return
    end
    
    if f(a)==0
     fprintf('%i is one of the root',a);
     return
    elseif f(b)==0
     fprintf('%i is one of root',b);
    end
    
    fprintf("n             a            b              p             f(a)           f(b)            f(p)\n");     
    
    for i=1:100
       
       p=(a*f(b)-b*f(a))/(f(b)-f(a));
       fprintf('%i       %f       %f        %f        %f       %f        %f',i,a,b,p,f(a),f(b),f(p));
       fprintf('\n');
        
       if f(p)*f(a)<0
            b=p;
       else
            a=p;
       end
       
       if (abs(f(a))<=1.0E-4)
            break
        end
    end

    fprintf('the root :%f \n the number of iteration of falsy position :%d\n',a,i);
end
