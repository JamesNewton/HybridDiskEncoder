// title      : OpenJSCAD.org encoder disk
// author     : James Newton
// license    : MIT License
// revision   : 0
// tags       : hdrobotics.com
// file       : encoderdisk.jscad

function getParameterDefinitions() {
  return [
    { name: 'disk', type: 'float', initial: 77, caption: "disk diameter:" },
    { name: 'hub', type: 'float', initial: 4, caption: "hub diameter:" },
    { name: 'slots', type: 'float', initial: 15.7, caption: "number of slots:" },
    { name: 'slotd', type: 'float', initial: 66, caption: "slots diameter:" },
    { name: 'slotlength', type: 'float', initial: 3.5, caption: "slot length:" },
    { name: 'cutfudge', type: 'float', initial: 0.4, caption: "laser cut width or<br> (-) filament spread:" },
    { name: 'thick', type: 'float', initial: 2, caption: "material thickness:" },
    ];
}


function main () {
var thick = params.thick
var slotwidth = Math.PI*params.disk/params.slots/2 - params.cutfudge;
// LED / photodiodes are T3, (3mm) so center to center ~4mm min
var senseslots = Math.ceil(4.0 / Math.PI*params.disk/params.slots)*2
var sensespace =  senseslots*1.5
var slotinc = 360.0/params.slots
var slots = []
   for(i=0.0; i<360; i+=slotinc) {
      slots.push(
        rotate([0,0,i], 
          translate([params.slotd/2,-slotwidth/2,-1], 
            square({size: [params.slotlength,slotwidth]})
            )
          )
        );
   }

var disk = circle({r: params.disk/2, fn: 50, center: true})
    .subtract(circle({r: params.hub/2, h:2, center: true}))
    .subtract(slots)
    ;
var base = square({size: [params.disk+10, params.disk+10], center:true})
    ;
var washer = circle({r:(params.hub/2+0.8), center: true})
    .subtract(circle({r:params.hub/2, h:2, center: true}));
var mask = square({size:[params.slotlength,sensespace], center:true})
var assembly = [
    linear_extrude({height: thick},base).setColor(1,0.5,0.3),
    linear_extrude({height: thick},washer).translate([0,0,thick]),
    linear_extrude({height: thick},mask).translate([params.slotd/2,0,thick]).setColor([0,0,0]),
    linear_extrude({height: thick},disk).translate([0,0,thick*2]),
    linear_extrude({height: thick},washer).translate([0,0,thick*3]),
    ];

return assembly;
}