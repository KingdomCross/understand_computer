clear,clc
%% º”‘ÿ ˝æ›
N10C30 = load('./C-serial/N10/C0.300000','r');
N10C35 = load('./C-serial/N10/C0.350000','r');
N10C40 = load('./C-serial/N10/C0.400000','r');

N20C30 = load('./C-serial/N20/C0.300000','r');
N20C35 = load('./C-serial/N20/C0.350000','r');
N20C40 = load('./C-serial/N20/C0.400000','r');

N30C30 = load('./C-serial/N30/C0.300000','r');
N30C35 = load('./C-serial/N30/C0.350000','r');
N30C40 = load('./C-serial/N30/C0.400000','r');


%% C= 0.3 N=10£¨20£¨30
figure(1)
plot(N10C30(:,1),N10C30(:,2),'r.')
hold on 

h1 = xlabel('$$x (m)$$');
h2 = ylabel('$$y (m)$$');

set([h1, h2],'interpreter','latex');
set([h1, h2],'FontName','Times New Roman','Color','Black');
set(gca,'FontName','Times New Roman','FontSize',10.5);
grid on

figure(2)
plot(N20C30(:,1),N20C30(:,2),'r.')
hold on 

h1 = xlabel('$$x (m)$$');
h2 = ylabel('$$y (m)$$');

set([h1, h2],'interpreter','latex');
set([h1, h2],'FontName','Times New Roman','Color','Black');
set(gca,'FontName','Times New Roman','FontSize',10.5);
grid on

figure(3)
plot(N30C30(:,1),N30C30(:,2),'r.')
hold on 

h1 = xlabel('$$x (m)$$');
h2 = ylabel('$$y (m)$$');

set([h1, h2],'interpreter','latex');
set([h1, h2],'FontName','Times New Roman','Color','Black');
set(gca,'FontName','Times New Roman','FontSize',10.5);
grid on

%% 

%% C= 0.35 N=10£¨20£¨30
figure(4)
plot(N10C35(:,1),N10C35(:,2),'r.')
hold on 

h1 = xlabel('$$x (m)$$');
h2 = ylabel('$$y (m)$$');

set([h1, h2],'interpreter','latex');
set([h1, h2],'FontName','Times New Roman','Color','Black');
set(gca,'FontName','Times New Roman','FontSize',10.5);
grid on

figure(5)
plot(N20C35(:,1),N20C35(:,2),'r.')
hold on 

h1 = xlabel('$$x (m)$$');
h2 = ylabel('$$y (m)$$');

set([h1, h2],'interpreter','latex');
set([h1, h2],'FontName','Times New Roman','Color','Black');
set(gca,'FontName','Times New Roman','FontSize',10.5);
grid on

figure(6)
plot(N30C35(:,1),N30C35(:,2),'r.')
hold on 

h1 = xlabel('$$x (m)$$');
h2 = ylabel('$$y (m)$$');

set([h1, h2],'interpreter','latex');
set([h1, h2],'FontName','Times New Roman','Color','Black');
set(gca,'FontName','Times New Roman','FontSize',10.5);
grid on

%% 

%% C= 0.3 N=10£¨20£¨30
figure(7)
plot(N10C40(:,1),N10C40(:,2),'r.')
hold on 

h1 = xlabel('$$x (m)$$');
h2 = ylabel('$$y (m)$$');

set([h1, h2],'interpreter','latex');
set([h1, h2],'FontName','Times New Roman','Color','Black');
set(gca,'FontName','Times New Roman','FontSize',10.5);
grid on

figure(8)
plot(N20C40(:,1),N20C40(:,2),'r.')
hold on 

h1 = xlabel('$$x (m)$$');
h2 = ylabel('$$y (m)$$');

set([h1, h2],'interpreter','latex');
set([h1, h2],'FontName','Times New Roman','Color','Black');
set(gca,'FontName','Times New Roman','FontSize',10.5);
grid on

figure(9)
plot(N30C40(:,1),N30C40(:,2),'r.')
hold on 

h1 = xlabel('$$x (m)$$');
h2 = ylabel('$$y (m)$$');

set([h1, h2],'interpreter','latex');
set([h1, h2],'FontName','Times New Roman','Color','Black');
set(gca,'FontName','Times New Roman','FontSize',10.5);
grid on

%% 