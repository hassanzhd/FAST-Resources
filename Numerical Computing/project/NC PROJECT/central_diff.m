function central_diff()
    t=input('Enter Co-ordinates values in bracket form:');
    o=input('Enter Co-ordinates values in bracket form:');
    
    p=0;
    r=0;
    
    dt=zeros(size(t,1),size(t,2)+1);
    
    for i=1:(size(t,2))
        dt(i,1)=t(i);
        dt(i,2)=o(i);
    end
    
    n=4;
    for j=3:(size(t,2)+1) 
        for i=1:n
            dt(i,j)=dt((i+1),(j-1))-dt(i,(j-1));
        end
        n=n-1;
    end
    
    h=t(2)-t(1);
    tp=27;
    
    for i=1:(size(t,2))
        q=(tp-t(i))/h;
        if(q>(-0.25)&&q<(0.25))
            p=q;
        end
    end
    
    l=tp-(p*h);
    
    for i=1:(size(t,2)) 
        if(l==t(i))
            r=i;
        end
    end 
    
    f0=o(r);
    f11=dt((r-1),3);
    f12=dt((r+1),3); 
    f02=dt((r-1),4); 
    f31=dt((r-2),5); 
    f32=dt((r-1),5); 
    f04=dt((r-2),6); 
    fp=f0+(p*(f11+f12))/2+((p*p)*f02)/2+(p*((p*p)-1)*(f31+f32))/12+((p*p)*((p*p)-1)*f04)/24;
end    