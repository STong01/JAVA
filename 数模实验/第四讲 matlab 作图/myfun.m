function Y = myfun(x)
Y(:,1) = 200*sin(x(:))./x(:);
Y(:,2) = x(:).^2;
fh = @myfun;
fplot(fh,[-20 20])