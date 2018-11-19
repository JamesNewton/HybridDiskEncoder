# Hybrid Disk Encoder

This encoder is based on the Haddington Dynamic Analog / Digital Hybrid encoders used on the Dexter robot arm:<br>
https://github.com/HaddingtonDynamics/Dexter/wiki/Encoders
<br>Please take a moment to read and understand that revolutionary system before continuing here; many of the goals of this project won't
make sense with out understanding it.

**Laser cut:** Instead of using 3D printed disks, this project will focus on laser cut parts. As laser cutters become more available and lower cost, 
their greater resolution and the simplicity of not supporting 3 dimisional objects may provide a cleaner signal and easy processing.

**Firmeware only, no FPGA required:** Because the primary goal of this project is to enable a very low cost human input device, it will not depend on FPGA speed, as humans
don't move that fast, and have builtin motion control systems that avoid the need for a high speed feedback loop. 

**OpenJSCAD:** In keeping with the focus on Javascript in DDE (the Dexter IDE), node.js processing for remote control, and an upcoming 
<a href="https://github.com/JamesNewton/AdvancedRoboticsWithJavascript/wiki">Robotics class</a>, this project uses<br>
http://OpenJSCAD.com
<br>as the CAD system of choice. This is unusual and may deter collaboration (hopefully not) but if you look at the code for a while,
it becomes obvious that it just isn't that different from a regular cad system. The CAD system can be viewed and played with at:<br>
http://openjscad.com/#https://gist.githubusercontent.com/JamesNewton/c8598878736442c440bbe41d086291ac/raw//encoderdisk.jscad
<br>Use the mouse to turn the model (shift to shift, ctrl or scroll to zoom), scroll through the code on the right, 
and edit parameters in the control block lower left. Switch from "Assembly" to "Parts" (bottom control block) to generate DXF or SVG
output for cutting. 

**Electronics** At this point, we are focused on the 
<A href="http://www.cypress.com/products/32-bit-arm-cortex-m0-psoc-4200-programmable-digital-blocks">Cypress PSoC 4 chips</A>
for the processor, with only opto sensors, and LEDs, (and USB serial interface).<br>
http://www.cypress.com/part/cy8c4247azi-m485
<br>This gives us:
- 8 channel, 12 bit ADC 1-Msps, 
- programmable analog front end (no need for external opamps or manual level adj), 
- 128K FLASH, 16K RAM, 48 Mhz, 32 bit ARM Cortex-M0.

And if we want to include support for high speed slot counting in the future: 48 macrocells for some FPGA ability. 

It is featured in this development system:<br>
http://www.cypress.com/documentation/development-kitsboards/cy8ckit-043-psoc-4-m-series-prototyping-kit $10 WITH a debugger!
The importance of a good debugger can not be overstated. 

The IDE includes schematic capture FPGA designer, etc... But it is Windows only IDE. However it is open source and has been 
built on Linux<br>
https://hackaday.io/project/18590-psoc-on-linux <br>
https://github.com/clementleger/cypress_linux_tools

And can apparently be run under wine<br>
https://appdb.winehq.org/objectManager.php?sClass=application&iId=16168

**Layers**<br>
Encoder center hub layers: 
- base w/ bearing, 
- washer (on bearing inner race), 
- opaque disk support and code disk, 
- moving arm, 
- washer, 
- bearing in top support arm. 

At edge: 
- base w/ holes for M3 screws and emitters, 
- opaque mask, (code disk edge),
- riser x2,
- opaque mask, 
- detector mount, 
- top support arm. 

## Building the Firmware
**IDE:** To start with the cy8ckit-043, you want this link:<br>
http://www.cypress.com/file/199476
<br>for both the Creator IDE and the support files for that hardware. 

## Questions:
Detector to support mount should be adjustable? Or will laser cut and assembly be accurate enough?

## Status:
- Done: CAD encoder, (some disks have been lasercut and appear to work well.)
- TODO: Order parts for electronics
- TODO: Order thin (1 or 2mm) acrylic and black / opaque cardstock.
- TODO: Lasercut parts for test assembly, update CAD as needed
- TODO: Order bearings, update CAD to support.
- TODO: Write test program for A2D feedback to PC. 
- TODO: Connect LEDs / Sensors to dev board, test and update design 
- TODO: Add AGC (Automatic Gain Control) to update onboard opamp gain.
- TODO: Calculate ATAN2 on board and return degrees
- TODO: Produce and assemble multiple joints into a non-driven arm with the same physical characteristics as Dexter
- TODO: Add DDE support for serial connected device as an input only Dexter
- TODO: Count pulses with on board digital logic for high speed operation?
- TODO: Develop cycloidal drive and add motor / drive support?


