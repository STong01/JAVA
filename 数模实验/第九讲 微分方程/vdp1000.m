function dy=vdp1000(t,y)
    dy=zeros(2,1);
    dy(1)=y(2);
    dy(2)=1000*(1-y(1)^2)*y(2)-y(1);