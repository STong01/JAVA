m=101;
x=0:2*pi/(m-1):2*pi;
y=sin(x);z=0*x;
plot(x,z,'r',x,y,'LineWidth',1.5),
gtext('y=sin(x)'),pause

n=3;
x0=0:2*pi/(m-1):2*pi;
y0=sin(x0);
y1=lagr1(x0,y0,x);
hold on,plot(x,y1,'b'),pause,
hold off

n=5;
x0=0:2*pi/(m-1):2*pi;
y0=sin(x0);
y2=lagr1(x0,y0,x);
hold on,plot(x,y2,'b:'),pause,
hold off

n=7;
x0=0:2*pi/(m-1):2*pi;
y0=sin(x0);
y3=lagr1(x0,y0,x);hold on,
plot(x,y3,'r'),pause,
hold off

n=9;
x0=0:2*pi/(m-1):2*pi;
y0=sin(x0);
y4=lagr1(x0,y0,x);hold on,
plot(x,y4,'r:'),pause,
hold off

n=11;
x0=0:2*pi/(m-1):2*pi;
y0=sin(x0);
y5=lagr1(x0,y0,x);hold on,
plot(x,y5,'m'),