# Hybrid Disk Encoder

This encoder is based on the Haddington Dynamic Analog / Digital Hybrid encoders used on the Dexter robot arm:<br>
https://github.com/HaddingtonDynamics/Dexter/wiki/Encoders
<br>Please take a moment to read and understand that revolutionary system before continuing here; many of the goals of this project won't
make sense with out understanding it.

**Laser cut:** Instead of using 3D printed disks, this project will focus on laser cut parts or PCBs. 
As laser cutters become more available and lower cost, their greater resolution and the simplicity of not supporting 3 dimisional objects may provide a cleaner signal and easy processing.
PCBs can be milled with excellent precision and are very strong, opaque, and can support silk screen as well as through-slots.

**Firmware only, no FPGA required:** Because the primary goal of this project is to enable a very low cost encoder, it will not depend on FPGA speed.
One application is for a human input device, and as humans don't move that fast, and have builtin motion control systems that avoid the need for a high speed feedback loop. 
When used as an encoder for robotics, rapid motion can be supported by switching to digital reading of the quadrature sensors, or via an inner single track grey code.

For now, the math.h atan2 is fast enough, but if we feel the need for speed:
- Interesting discussion of ultra ATAN2 methods:
https://web.archive.org/web/20180529001306/https://www.coranac.com/documents/arctangent/
- http://f3.to/portfolio/math/fastatan2.htm Fast atan2. `if |X|>|Y| [(-b*x*y)/(x^2+ a*y^2) + c*sign(x)] else [-c*sign(x*y)= c*sign(x) + (b*x*y)/(y^2+a*x^2)] where a = 0.28088, b = 180/Pi, c = b/2*Pi`

**OpenJSCAD:** In keeping with the focus on Javascript in DDE (the Dexter IDE), node.js processing for remote control, and an upcoming 
<a href="https://github.com/JamesNewton/AdvancedRoboticsWithJavascript/wiki">Robotics class</a>, this project uses<br>
https://OpenJSCAD.com
<br>as the CAD system of choice. This is unusual and may deter collaboration (hopefully not) but if you look at the code for a while,
it becomes obvious that it just isn't that different from a regular cad system. The CAD system can be viewed and played with at:<br>
https://openjscad.com/#https://raw.githubusercontent.com/JamesNewton/HybridDiskEncoder/master/encoderdisk.jscad
(note: that link seems not to work directly, but if you go to OpenJSCAD.com first, then copy in the code above, it does work)
<br>Use the mouse to turn the model (shift to shift, ctrl or scroll to zoom), scroll through the code on the right, 
and edit parameters in the control block lower left. Switch from "Assembly" to "Parts" (bottom control block) to generate DXF or SVG
output for cutting. 

**Electronics** Previously, we focused on the 
<A href="http://www.cypress.com/products/32-bit-arm-cortex-m0-psoc-4200-programmable-digital-blocks">Cypress PSoC 4 chips</A>
for the processor, with only opto sensors, and LEDs, (and USB serial interface).<br>
http://www.cypress.com/part/cy8c4247azi-m485
It is featured in this development system:<br>
http://www.cypress.com/documentation/development-kitsboards/cy8ckit-043-psoc-4-m-series-prototyping-kit $10 WITH a debugger!
The importance of a good debugger can not be overstated. 
<br>This gives us:
- 8 channel, 12 bit ADC 1-Msps, 
- programmable analog front end (no need for external opamps), 
- PWM output to adjust emmiter brightness (no need for manual adjust),
- 128K FLASH, 16K RAM, 48 Mhz, 32 bit ARM Cortex-M0.

However, 
1. it can NOT be run under wine<br>
https://appdb.winehq.org/objectManager.php?sClass=application&iId=16168
2. And the need for a frontend is removed by a little digital filtering and using PWM to control the brightness of the LEDs. 

Happily, it turns out the PiPico is perfectly capable. The A2D is less able, but for a first version, it's perfectly able, and less complex. 

<table><tr><td>
<img src="https://raw.githubusercontent.com/JamesNewton/HybridDiskEncoder/master/docs/HybridEncoderFront.jpg">
  </td><td>
<img src="https://raw.githubusercontent.com/JamesNewton/HybridDiskEncoder/master/docs/HybridEncoderBack.jpg" >
  </td></tr></table>
  
**Layers**<br>
Encoder center hub layers: 
- base, 
- washer,
- opaque disk support and code disk, 
- moving arm, 
- washer, 
- top support arm. 

At edge:
- emitter mount, (below base)
- base w/ holes for M3 screws and emitters, 
- riser x2,
- opaque mask, 
- detector mount, 
- top support arm (w/holes for detectors). 

## Building the Firmware
**IDE:** Just the current Arduino IDE or https://wokwi.com/ 

## Questions:
Detector to support mount should be adjustable? Or will laser cut and assembly be accurate enough?

## Status:
- Done: CAD encoder, (some disks have been lasercut and appear to work well.)
- Done: Order parts for electronics
- Done: Order thin (1 or 2mm) acrylic and black / opaque cardstock. 110lb Cardstock with 3mm Acrylic seems to work
- Done: Lasercut parts for test assembly, update CAD as needed
- Done: Write test firmware for PWM control of the LEDs and A2D feedback to PC. 
- Done: Connect LEDs / Sensors to dev board, test and update design 
- Done: Set the PWM levels on the LEDs to get full range response on the A2D
- Done: Calculate ATAN2 on board and return degrees. 
- TODO: Count slots with the hardware and combine with ATAN2 degrees
- TODO: Open shaft passthrough <a href="https://github.com/JamesNewton/HybridDiskEncoder/issues/6">#6</a>
- TODO: Add support for Single Track Grey Code absolute position. See <a href="https://github.com/JamesNewton/HybridDiskEncoder/issues/5">#5</a>
- TODO: Add <a href="https://cfry.github.io/dde4/dde/index.html">DDE4</a> support for serials connected devices
- TODO: Produce and assemble a joint with shaft pass through, integrated (on joint) encoder, separate(able) drive box for different motor sizes / types. 

## See also:
- https://photos.app.goo.gl/v6FCJX8Efcgw1NGY7 photo album of ongoing work. 
