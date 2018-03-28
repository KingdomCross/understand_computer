clear,clc
%% º”‘ÿ ˝æ›
N10C20 = load('./C-serial/N10/C0.000000','r');
N10C25 = load('./C-serial/N10/C0.350000','r');
N10C30 = load('./C-serial/N10/C0.400000','r');

N20C20 = load('./C-serial/N20/C0.300000','r');
N20C25 = load('./C-serial/N20/C0.350000','r');
N20C30 = load('./C-serial/N20/C0.400000','r');

N30C20 = load('./C-serial/N30/C0.300000','r');
N30C25 = load('./C-serial/N30/C0.350000','r');
N30C30 = load('./C-serial/N30/C0.400000','r');


%%
figure(1)
plot3(N10C20(:,1),N10C20(:,2),N10C20(:,3) ,'r.')
hold on 

h1 = xlabel('$$x (m)$$');
h2 = ylabel('$$y (m)$$');
h3 = zlabel('$$z (m)$$');

set([h1, h2, h3],'interpreter','latex');
set([h1, h2, h3],'FontName','Times New Roman','Color','Black');
set(gca,'FontName','Times New Roman','FontSize',10.5);
grid on

figure(2)
plot3(N20C20(:,1),N20C20(:,2),N20C20(:,3) ,'r.')
hold on 

h1 = xlabel('$$x (m)$$');
h2 = ylabel('$$y (m)$$');
h3 = zlabel('$$z (m)$$');

set([h1, h2, h3],'interpreter','latex');
set([h1, h2, h3],'FontName','Times New Roman','Color','Black');
set(gca,'FontName','Times New Roman','FontSize',10.5);
grid on

figure(3)
plot3(N30C20(:,1),N30C20(:,2),N30C20(:,3) ,'r.')
hold on 

h1 = xlabel('$$x (m)$$');
h2 = ylabel('$$y (m)$$');
h3 = zlabel('$$z (m)$$');

set([h1, h2, h3],'interpreter','latex');
set([h1, h2, h3],'FontName','Times New Roman','Color','Black');
set(gca,'FontName','Times New Roman','FontSize',10.5);
grid on

%%
% ########################################################

%%
figure(4)
plot3(N10C30(:,1),N10C30(:,2),N10C30(:,3) ,'r.')
hold on 

h1 = xlabel('$$x (m)$$');
h2 = ylabel('$$y (m)$$');
h3 = zlabel('$$z (m)$$');

set([h1, h2, h3],'interpreter','latex');
set([h1, h2, h3],'FontName','Times New Roman','Color','Black');
set(gca,'FontName','Times New Roman','FontSize',10.5);
grid on

figure(5)
plot3(N20C30(:,1),N20C30(:,2),N20C30(:,3) ,'r.')
hold on 

h1 = xlabel('$$x (m)$$');
h2 = ylabel('$$y (m)$$');
h3 = zlabel('$$z (m)$$');

set([h1, h2, h3],'interpreter','latex');
set([h1, h2, h3],'FontName','Times New Roman','Color','Black');
set(gca,'FontName','Times New Roman','FontSize',10.5);
grid on

figure(6)
plot3(N30C30(:,1),N30C30(:,2),N30C30(:,3) ,'r.')
hold on 

h1 = xlabel('$$x (m)$$');
h2 = ylabel('$$y (m)$$');
h3 = zlabel('$$z (m)$$');

set([h1, h2, h3],'interpreter','latex');
set([h1, h2, h3],'FontName','Times New Roman','Color','Black');
set(gca,'FontName','Times New Roman','FontSize',10.5);
grid on


%%

