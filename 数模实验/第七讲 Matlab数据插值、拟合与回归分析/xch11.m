x=linspace(-5,5,100);
y=1./(x.^2+1);
x1=linspace(-5,5,5);
y1=1./(x1.^2+1);
plot(x,y,x1,y1,x1,y1,'o','LineWidth',1.5),
title('n=4')
