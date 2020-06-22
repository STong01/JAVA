xdata=0:0.1:1;
ydata=[3.1,3.27,3.81,4.5,5.18,6,7.05,8.56,9.69,11.25,13.17];
x0=[0,0,0];
[x,resnorm]=lsqnonlin('nihehanshu',x0,xdata,ydata)
