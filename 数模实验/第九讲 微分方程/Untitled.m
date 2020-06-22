x=0;y=0;
w=5;
dt=0.1

for t=0:0.1:100

d=sqrt((x1(t)-x)^2+(y1(t)-y)^2);
x=w*((x1(t)-x)/d)*dt+x;
y=w*((y1(t)-y)/d)*dt+y;

plot(x1(t),y1(t),'r+',x,y,'*')
hold on 
end

