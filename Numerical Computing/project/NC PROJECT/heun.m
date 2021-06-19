function heun()
    %Heun's method
    func = input('Enter function in terms of x and y: ', 's');
    heuns = inline(func,'x' , 'y');
    t_init = input('Enter lower bound of range: ');
    t_final = input('Enter upper bound of range: ');
    y_init = input('Enter initial y value: ');
    n = input('Enter number of iterations' );


    h = (t_final - t_init)/n;                                                
    t=[t_init zeros(1,n)]; 
    w=[y_init zeros(1,n)];

     for i = 1:n+1 
      t(i+1) = t(i) + h;
      W = w(i) + (h/3) * heuns( t(i) , w(i) );
      w(i+1) = w(i) + (h/4) * ( heuns(t(i),w(i)) + 3 * heuns(t(i)+(2 * h/3), w(i)+(2 * h/3) * heuns(t(i)+h/3, W)));
     end
end