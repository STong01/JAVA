x=[1949:5:1994]; 
y=[5.4  6.0  6.7  7.0  8.1  9.1  9.8  10.3 11.3  11.8 ]; 
a=polyfit(x,y,1)
y1=a(2)+a(1)*x;
polyval(a,1999)
polyval(a,2000)



b=polyfit(x,log(y),1) 
y2=exp(b(2))*exp(b(1)*x); 

plot(x,y,'*') 
hold on 
plot(x,y1,'--r') 
hold on 
plot(x,y2,'-k') 
legend('原曲线','模型一曲线','模型二曲线') 
