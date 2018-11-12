// title      : OpenJSCAD.org encoder disk
// author     : James Newton
// license    : MIT License
// revision   : 0
// tags       : hdrobotics.com
// file       : encoderdisk.jscad
// http://openjscad.com/#https://gist.githubusercontent.com/JamesNewton/c8598878736442c440bbe41d086291ac/raw//encoderdisk.jscad

function getParameterDefinitions() {
  return [
    { name: 'disk', type: 'float', initial: 77, caption: "disk diameter:" },
    { name: 'hub', type: 'float', initial: 4, caption: "hub diameter:" },
    { name: 'slots', type: 'int', initial: 80, caption: "number of slots:" },
    { name: 'slotd', type: 'float', initial: 66, caption: "slots diameter:" },
    { name: 'slotlength', type: 'float', initial: 3.5, caption: "slot length:" },
    { name: 'mask', type: 'float', initial: 0.8, caption: "slot mask width:" },
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
var basesize=params.disk+10
var base = square({size: [basesize, basesize], center:true})
    .subtract(translate([params.slotd/2+params.slotlength/2,+sensespace/2,0],circle({r:1.5, center:true})))
    .subtract(translate([params.slotd/2+params.slotlength/2,-sensespace/2,0],circle({r:1.5, center:true})))
    base.w = basesize; base.h = basesize;
var washer = circle({r:(params.hub/2+0.8), center: true})
    .subtract(circle({r:params.hub/2, h:2, center: true}));
var mask = square({size:[params.slotd-basesize,sensespace+6], center:true})
    .subtract(translate([params.slotlength/2,+sensespace/2,0],rotate([0,0,+slotinc],square({size: [params.slotlength,params.mask], center:true}))))
    .subtract(translate([params.slotlength/2,-sensespace/2,0],rotate([0,0,-slotinc],square({size: [params.slotlength,params.mask], center:true}))))
var assembly = [
    linear_extrude({height: thick},base).setColor(1,0.5,0.3),
    linear_extrude({height: thick},washer).translate([0,0,thick]),
    linear_extrude({height: thick},mask).translate([params.slotd/2,0,thick]).setColor([0,0,0]),
    linear_extrude({height: thick},disk).translate([0,0,thick*2]),
    linear_extrude({height: thick},washer).translate([0,0,thick*3]),
    ]
var cut = []
    cut.push(base)
    placeright(mask,cut)
    placeright(washer,cut)
    placeright(washer,cut)
return cut;
}

function placeright(o,a) {
    edge = a.reduce((t, e) => t + e.getBounds()[1].x, 0)
    edge += o.getBounds()[1].x/2
    a.push(translate([0,edge], o))
    }
    
    