x=-5:0.1:5;
y=1./(1+x.^2);
xi=-5:2.5:5;
yi=interp1(x,y,xi);
plot(x,y,'b',xi,yi,'r')
