# Rickshaw_meter_arduino



Problems


1. 
I think measuring speed with an IR sensor is not a good idea. I have tried this method in a project and noticed that it gives inaccurate values. 

The problem with this method is: 

Arduino operates at 16MHz frequency. It means it can execute an instruction at 62.5 ns.Let's assume any arduino function takes 100 instructions to be executed. That  function can be executed within 625 ns. 

Let's take 1 ms for easier calculation. 
If the black marked portion of the wheel takes more than 1 ms to disappear in front of the IR sensor, it will be calculated multiple times. That causes the inaccuarcy. 

I think you can use a motor with a magnetic encoder to rotate the wheel. It will automatically feedback data to the arduino and according to the position of the encoder, the speed can be calculated.  


2
I did an arbitrary calculation for the road steepness, where I used an arbitrary formula. Hopefully, you can change it.  

3
Same goes for the calculation of fare. I used arbitrary values. I think the formula used to calculate the wind speed has flaw. 

4
I have deleted all the Serial. print() command as those use interrupts. Besides, I don’t think someone needs to attach a pc with a rickshaw meter in practice. You can debug the code with proper use of the Serial.print() command. 

5
I expect many errors in real time applications. This code may not run properly. Even it may not run at all! 
The sole reason for this is I have not been able to test the code with sensors. 

I hope you will check it  for me and let me know the errors. I will certainly solve those issues. In that case, I will try to arrange those hardwares and test it for myself. 

