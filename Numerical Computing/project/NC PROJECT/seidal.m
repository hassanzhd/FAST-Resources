function seidal()
    syms x1 x2 x3 x4 x5 x6 % all max required symbols

    n=input('Enter number of equations: '); % number of equations
    eqns=sym(zeros(1,n)); % equation array
    initialValues=zeros(1,n); % substition array

    for i=1:n
       eqns(i)=input('Enter equation: '); % equation input
       initialValues(i)=0; % initial values array
    end

    iterations=input('Enter number of iterations: ');

    flag=0;

    [A,b]=equationsToMatrix(eqns); % this function converts inputted equation to matrix of coefficients

    for i=1:n
        temp=0;

        for j=1:n
            if(j==i)
                continue;
            end
            temp=temp+abs(A(i,j));
        end

        if A(i,i) < temp
            flag=1;
            break;
        end

    end % loop to check if array is diagonally dominant

    if flag==0
        for i=1:n
            switch i
                case 1
                    fx1=solve(eqns(i),x1);
                    fx1=matlabFunction(fx1);
                    disp(fx1);
                case 2
                    fx2=solve(eqns(i),x2);
                    fx2=matlabFunction(fx2);
                    disp(fx2);
                case 3
                    fx3=solve(eqns(i),x3);
                    fx3=matlabFunction(fx3);
                    disp(fx3);
                case 4
                    fx4=solve(eqns(i),x4);
                    fx4=matlabFunction(fx4);
                    disp(fx4);
                case 5
                    fx5=solve(eqns(i),x5);
                    fx5=matlabFunction(fx5);
                    disp(fx5);
                case 6
                    fx6=solve(eqns(i),x6);
                    fx6=matlabFunction(fx6);
                    disp(fx6);
            end
        end % % creating required expression in terms of all variable (i.e. x1, x2, x3....)

        for i=1:iterations
            for j=1:n
                tempArray=initialValues(1:n~=j);
                arguments=num2cell(tempArray);
                switch j
                    case 1
                      initialValues(j)=fx1(arguments{:});
                      disp(initialValues(j));
                    case 2
                      initialValues(j)=fx2(arguments{:});
                      disp(initialValues(j));
                    case 3
                      initialValues(j)=fx3(arguments{:});
                      disp(initialValues(j));
                    case 4
                      initialValues(j)=fx4(arguments{:});
                      disp(initialValues(j));
                    case 5
                      initialValues(j)=fx5(arguments{:});
                      disp(initialValues(j));             
                    case 6
                      initialValues(j)=fx6(arguments{:});
                      disp(initialValues(j));
                end
            end
            initialValues=initialValues(1:n); % computed values are copied to original array
        end
        % since number of arguments are known at runtime hence cells are used, required
        % variables are get from initialValue array and then converted to
        % cell and passed using argument{:} syntax
    end 

    if flag==1
        disp("NOT DIAGONALY DOMINANT");
    end
end