// SynthDef
(
SynthDef("reverb", {
	arg wet=1.0;
	var in, fx;
	in = In.ar(0, 2);
	fx = in;
	fx = GVerb.ar(fx, 80);
	ReplaceOut.ar(0, fx);
}).store;

SynthDef("baseSound", {
	arg note=40, amp=0.1, fadein=12.0;
	var env, out;
	env = EnvGen.kr(Env.new([0, amp], [fadein]));
	out = RLPF.ar(LFPulse.ar([note, note+7].midicps, 0.15), SinOsc.kr(0.1, 0, 10, 72).midicps, 0.1, 0.1);
	Out.ar(0, out*env);
}).store;

SynthDef("newRing", {
	arg note=40, amp=0.5, pan = 0.0, decay=4.0;
	var env1, out1, env2, out2, mix;
	out1 = RLPF.ar(LFPulse.ar([note, note+7].midicps, 0.15), SinOsc.kr(0.1, 0, 10, 72).midicps, 0.1, 0.1);
	out2 = SinOsc.ar([(note+48).midicps, (note+55).midicps]);
	env1 = EnvGen.kr(Env.perc(decay/4.0, decay/4.0*3.0, amp, -4), doneAction: 2);
	env2 = EnvGen.kr(Env.adsr(0.001, 0.4, 0.0, decay, amp*0.1, -4));
	mix = (out1 * env1) + (out2 * env2);
	mix = CombN.ar(mix, 0.31, 0.31, 2, 0.5, mix);
	Out.ar(0, mix);
}).store;
)

// test
s.sendMsg("/s_new", "reverb", x = s.nextNodeID, 1, 1);
s.sendMsg("/s_new", "baseSound", x = s.nextNodeID, 1, 1);
s.sendMsg("/s_new", "newRing", x = s.nextNodeID, 1, 1, "note", 42);