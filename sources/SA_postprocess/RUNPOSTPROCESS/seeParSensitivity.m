% 26 June 2018.
% SRK. This code is part of PM3 platform.
% Licenced for use in KCRU, VH Kharche-McIntyre groups/labs with permission.
%
% Program to see how diastolic BP, systolic BP in LV,  diastolic BP, systolic BP in systemic artery, systemic venous flow, PV loops, and PV area looks like
% when paramters are changed.

% Input:
% files numbered with whichPar and parMult with col 1: time, 14 states, and 34 algebriac columns.

% Info:
%   There are a total of 34 entries in the algebraic variable array.
%   There are a total of 14 entries in each of the rate and state variable arrays.
%   There are a total of 88 entries in the constant variable array.

close all
close all
clear all
clear all

debg = 1;
% loop variables.
for whichPar = 1:1:7
for parMult = 1:1:200

% if(whichPar>1 || parMult > 2 || debg == 0)
%	debg = 1;
%	fprintf('do not put so many pictures on screen, you will jam it all up. Switching off pictures OKAY!\n');
% end;


str = sprintf('output_%d_%d.dat', whichPar, parMult);
rawData = load(str);

timee = rawData(:,1) - rawData(1,1); % time vector, column 1 in the output files.

% get the LV pressure, systemic artery pressure, systemic venous flow.
% LV pressure.
lvPressure = rawData(:, 22);
% systolic LV pressure
[lvpks1,lvlocs1] = findpeaks(lvPressure); % systolic values.
[lvpks2,lvlocs2] = findpeaks(-lvPressure);
lvpks2 = -lvpks2;
if(debg==0) figure; plot(timee, lvPressure, timee(lvlocs1), lvPressure(lvlocs1), 'r*', timee(lvlocs2), lvPressure(lvlocs2), 'g*'); end;

% systemic artery pressure.
sysArteryPressure = rawData(:,8);
% systolic artery pressure.
[lvpks3,lvlocs3] = findpeaks(sysArteryPressure); % systolic values.
[lvpks4,lvlocs4] = findpeaks(-sysArteryPressure);
lvpks4 = -lvpks4;
if(debg==0) figure; plot(timee, sysArteryPressure, timee(lvlocs3), sysArteryPressure(lvlocs3), 'r*', timee(lvlocs4), sysArteryPressure(lvlocs4), 'g*'); end;

% systemic vein flow.
sysVeinFlow = rawData(:,(1+14+32));
% systolic artery pressure.
[lvpks5,lvlocs5] = findpeaks(sysVeinFlow); % systolic values.
[lvpks6,lvlocs6] = findpeaks(-sysVeinFlow);
lvpks6 = -lvpks6;
if(debg==0) figure; plot( timee, sysVeinFlow , timee(lvlocs5), sysVeinFlow(lvlocs5), 'r*', timee(lvlocs6), sysVeinFlow(lvlocs6), 'g*' ); end;


% prepare data.
systolicLVpressure = mean(lvPressure(lvlocs1));
diastolicLVpressure = mean(lvPressure(lvlocs2));

systolicArteryPressure = mean( sysArteryPressure(lvlocs3) );
diastolicArteryPressure = mean( sysArteryPressure(lvlocs4) );

systolicVeinFlow = min( sysVeinFlow(lvlocs5) );
diastolicVeinFlow = min( sysVeinFlow(lvlocs6) );

% pv loop.
pv = [lvPressure rawData(:,4)];
if(debg==0)  figure; plot(pv(:,1), pv(:,2));  end;

polyareaa = polyarea(pv(:,1), pv(:,2));

% for plotting.
output = [whichPar parMult systolicLVpressure diastolicLVpressure systolicArteryPressure diastolicArteryPressure systolicVeinFlow diastolicVeinFlow polyareaa];

str = sprintf('LuisFigs_%d.dat', whichPar);
dlmwrite(str, output, '-append', 'delimiter','\t');
clear str;

% clear everything except for whichPar and parMult.
clearvars -except whichPar parMult debg;

end;
end;


close all;
close all;
clear all;
clear all;

% now plot it all to pngs.
figure;
% LV systolic pressure.
cmap = jet(7);
for whichPar = 1:1:7
str = sprintf('LuisFigs_%d.dat', whichPar);
data = load(str);
clear str;
% plot the systolic BP.
plot(data(:,2), data(:,3),'c', 'LineWidth', 3, 'Color', cmap(whichPar, :)); % have a consistent line colour for each paramter.
hold on;
end;
xlabel('x parameter value', 'FontSize', 18);
ylabel('LV Systolic mmHg', 'FontSize', 18);
box off;
legend boxoff;
set(gca, 'FontSize', 18);
axis([0 200 0 500]);
legend('R_{SAT}', 'RSCP', 'RSAR', 'RSVN', 'RSAS', 'CSAT', 'LSAT');
saveas(gcf,'LVSystolic.png');

figure;
% Systemic artery systolic pressure.
for whichPar = 1:1:7
str = sprintf('LuisFigs_%d.dat', whichPar);
data = load(str);
clear str;
% plot the systolic BP.
plot(data(:,2), data(:,5),'c','LineWidth', 3, 'Color', cmap(whichPar, :));
hold on;
end;
xlabel('x parameter value', 'FontSize', 18);
ylabel('Systemic artery (aorta) \n Systolic mmHg', 'FontSize', 18);
box off;
legend boxoff;
set(gca, 'FontSize', 18);
axis([0 200 0 500]);
legend('R_{SAT}','RSCP','RSAR','RSVN','RSAS','CSAT', 'LSAT');
saveas(gcf,'ArterialSystolic.png');



figure;
% Systemic vein blood flow.
for whichPar = 1:1:7
str = sprintf('LuisFigs_%d.dat', whichPar);
data = load(str);
clear str;
% plot the systolic BP.
plot(data(:,2), data(:,7),'c','LineWidth', 3, 'Color', cmap(whichPar, :));
hold on;
end;
xlabel('x parameter value', 'FontSize', 18);
ylabel('Systemic vein (SVC) \n flow ml/s', 'FontSize', 18);
box off;
legend boxoff;
set(gca, 'FontSize', 18);
axis([0 200 0 130]);
legend('R_{SAT}','RSCP','RSAR','RSVN','RSAS','CSAT', 'LSAT');
saveas(gcf,'VenaCavaFlow.png');
