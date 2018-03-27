CNP = load('points_C_N.txt');
 
figure(1)
% plot3(CNP(:,1),CNP(:,2),CNP(:,3),'b*');
plot3(CNP(:,1),CNP(:,2),CNP(:,3),'.')
h1 = xlabel('$$C (m)$$');
h2 = ylabel('$$N (m)$$');
h3 = zlabel('$$P (m)$$');

set([h1, h2, h3],'interpreter','latex');
set([h1, h2, h3],'FontName','Times New Roman','Color','Black');
set(gca,'FontName','Times New Roman','FontSize',10.5);
grid minor


figure(2)
x0 = 0:0.05:0.95;
y0 = 10:10:200;
size(x0)
size(y0)
size(CNP(:,3))
z = (reshape(CNP(:,3), max(size(x0)), max(size(y0))))';

[x, y] = meshgrid(x0,y0);
surf(x,y,z)
shading interp;

hold on
mesh(x,y,z)
plot3(CNP(:,1),CNP(:,2),CNP(:,3),'.')

h1 = xlabel('$$C (m)$$');
h2 = ylabel('$$N (m)$$');
h3 = zlabel('$$P (m)$$');

set([h1, h2, h3],'interpreter','latex');
set([h1, h2, h3],'FontName','Times New Roman','Color','Black');
set(gca,'FontName','Times New Roman','FontSize',10.5);
grid minor