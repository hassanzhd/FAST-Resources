function [] = SDT_DDT()
    c= input('Enter values of x in format [start:seperation:end] ');
    x= zeros (1,10);
    for i=1 : size(c,2)
        x(i)= c(i);  
    end
    
    m = input('Enter value of m ');
    str = input('Give an equation in x: ','s')  ;
    f = inline(str,'x') ;
         if size(x)== 1
          y = feval(f,x) ;
        else
            y= zeros(size(x));
            for i=1:+1: size(x,2)
                y(i)= feval(f,x(i));
            end
        end
    a= input('1. newtons forward interpolation with DDT \n2. newtons forward interpolation with SDT\n3. newtons backward interpolation with DDT \n4. newtons backward interpolation with SDT\n ');
  

    if a==1 
        n=length(x); % Number of terms of X or Y
        d=zeros(n-1);
        h=x(2)-x(1); %step length
        x0=m;
        u=(x0-x(1))/h;
        for i=2:n %Calculation of first forward differences
         d(i-1,1)=y(i)-y(i-1);
        end
     for k=2:n-1 %Calculation of second and rest forward differences
          for i=1:n-k
             d(i,k)= d(i+1,k-1)-d(i,k-1);
          end
     end
      disp('The forward difference table is:')
      d
      s=y(1); t=u;
      for k=1:n-1 %Calculation of result
      s=s+t*d(1,k);
     t=(u-k)/(k+1)*t;
      end
     fprintf('The required value is f(%f)= %5.5f \n',x0,s);
    
     elseif a==2
             h=x(2)-x(1);
             p= (m-x(1))/h;
            
            [ b, a ] = size(x); % m points, polynomial order <= m-1
            if b ~= 1 || b ~=size(y, 1) || a ~= size(y, 2)
                error('divdiff: input vectors must have the same dimension'); 
            end
            TDD = zeros(a, a);
            TDD(:, 1) = y';
            for j = 2 : a
                for i = 1 : (a - j + 1)
                    TDD(i,j) = (TDD(i + 1, j - 1) - TDD(i, j - 1));
                end
            end
            C= zeros (10,1);
            for i=1 : a
                C(i)= TDD(1,i);  
            end
            fprintf('SDT table is: \n')
            TDD
            result = formula(C,p);
            fprintf('The required value is f(%f)= %5.5f \n',m,result);

    elseif a==3
            n=length(x); % Number of terms of X or Y
            d=zeros(n-1);
            h=x(2)-x(1); %step length
            xn= m;
            u=(xn-x(n))/h;
            for i=2:n %Calculation of first backward differences
               d(i-1,1)=y(i)-y(i-1);
            end
            for k=2:n-1  %Calculation of second and rest backward differences
              for i=1:n-k
                    d(i,k)= d(i+1,k-1)-d(i,k-1);
              end
            end
            disp('The backward difference table is:')
            d
            s=y(n); t=u; m=n-1;
            for k=1:n-1  %Calculation of result
              s=s+t*d(m,k);
              t=(u+k)/(k+1)*t;
              m=m-1;
            end
            fprintf('The required value is f(%f)= %5.5f',xn,s);
     
    elseif a==4
   
          h=x(2)-x(1);
          p= (m-x(end))/h;
        [ b, a ] = size(x); % m points, polynomial order <= m-1
        if b ~= 1 || b ~=size(y, 1) || a ~= size(y, 2)
            error('divdiff: input vectors must have the same dimension'); 
        end
        SDT = zeros(a,a);
        SDT(:, 1) = y';
        for j = 2 : a
            for i = 1 : (a - j + 1)
                SDT(i,j) = (SDT(i + 1, j - 1) - SDT(i, j - 1));
            end
        end
        C= zeros (10,1);
        for i=1 : a
            C(i)= SDT(end+1-i,i);  
        end

    fprintf('SDT table is: \n')
    SDT
    result = formula(C,p);
    fprintf('The required value is f(%f)= %5.5f \n',m,result);
    else
        fprintf('Wrong choice');
    end

end

