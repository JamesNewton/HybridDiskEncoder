// title      : OpenJSCAD.org encoder disk
// author     : James Newton
// license    : MIT License
// revision   : 0
// tags       : hdrobotics.com
// file       : encoderdisk.jscad

function getParameterDefinitions() {
  return [
    { name: 'disk', type: 'float', initial: 77, caption: "diameter of the disk:" },
    { name: 'hub', type: 'float', initial: 2, caption: "diameter of the hub:" },
    { name: 'slots', type: 'float', initial: 157, caption: "number of slots:" },
    { name: 'slotd', type: 'float', initial: 66, caption: "distance slots from center:" },
    { name: 'slotlength', type: 'float', initial: 3.5, caption: "length of each slot:" },
    { name: 'cutfudge', type: 'float', initial: 0.4, caption: "width of laser cut / negative spread of printer filament:" },
    ];
}


function main () {
var slotwidth = Math.PI*params.disk/params.slots/2 - params.cutfudge;
var slotinc = 360.0/params.slots;
console.log(slotinc);
var slots = [];
   for(i=0.0; i<360; i+=slotinc) {
       console.log(i);
      slots.push(
        rotate([0,0,i], 
          translate([params.slotd/2,-slotwidth/2,-1], 
            cube({size: [params.slotlength,slotwidth, 2]})
            )
          )
        );
   }

return cylinder({r: params.disk/2, fn: 50})
    .subtract(cylinder({r: params.hub/2, h:2, center: true}))
    .subtract(slots)
    .translate([0, 0, 0])
    .scale(1);
}