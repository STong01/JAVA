
w=20
t=0:0.05:50;
n=length(t);
x=10+20*cos(t);
y=20+5*sin(t);
x1(1)=0;
y1(1)=0;
dt=0.05;
m=moviein(n);

for i=1:n
    d=sqrt((x(i)-x1(i))^2+(y(i)-y1(i))^2);
    x1(i+1)=x1(i)+w*dt*(x(i)-x1(i))/d;
    y1(i+1)=y1(i)+w*dt*(y(i)-y1(i))/d;
%    plot(x(i),y(i),'ro',x1(i),y1(i),'g*');
%    hold on
%     m(:,i)=getframe;

end
%  plot(x1,y1,'ro')
%     hold on
%      plot(x,y,'g*')