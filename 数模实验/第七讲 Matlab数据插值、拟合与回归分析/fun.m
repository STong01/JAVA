clear all;
x=0:0.12:1;
y=(x.^2-3*x+5).*exp(-5*x).*sin(x);
figure(1)
plot(x,y,x,y,'ro')
x0=0:0.02:1;
y0=(x0.^2-3*x0+5).*exp(-5*x0).*sin(x0);
y1=interp1(x,y,x0);
y2=interp1(x,y,x0,'pchip');
y3=interp1(x,y,x0,'spline');
y4=interp1(x,y,x0,'nearest');
figure(2)
plot(x0,[y1',y2',y3',y4'],x0,y0)
legend('linear','pchip','spline','nearest')