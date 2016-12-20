Description:

	The torque by the pedellar is varied on a sinusoid, efficiency is assumed to be 100% and some if statements were added to deal with border cases.

	We can see that the Output of the PID which tries to vary on a sine curve.

Status of the test :-

	PID speed was good enough although there are a few things to note:

		1). The PID function takes only double as Input and SetPoint so decimal number may not be allowed
		2). We have to set if statements in the PIDMain in order to avoid getting stuck in loops
		3). The test did not include usage of the convertVandSend function