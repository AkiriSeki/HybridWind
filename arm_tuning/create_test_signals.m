%% Create test signals



%% Forces

amplitude = 1;

u1 = prbs(16,2^16-1)'*2-1;

t2 = [0:0.001:60]';
u2 = chirp(t2,0.1,60,100,'logarithmic',-90);

u = [zeros(5000,1) ; u1 ; zeros(5000,1) ; u2];
t = [0:1:length(u)-1]*0.001;

u = u*amplitude;

figure,plot(t,u);

identinput_1 = timeseries;
identinput_1.Data = u;
identinput_1.Time = t;

save identinput_1 identinput_1