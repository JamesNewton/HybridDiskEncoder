// title      : OpenJSCAD.org encoder disk
// author     : James Newton
// license    : MIT License
// revision   : 0
// tags       : https://github.com/JamesNewton/HybridDiskEncoder
// file       : encoderdisk.jscad
// https://openjscad.org/#https://raw.githubusercontent.com/JamesNewton/HybridDiskEncoder/master/encoderdisk.jscad

//NOTES: 
// - The small parts, e.g. riser and washer, can be blown away by the laser cutter. Best to cut the inside holes at full power
//   and the outer parts at reduced power. Or to post edit the vectors to break the outer lines and leave tabs to hold them in.
// - Lasers alway cut with a bit of an angle. If the LEDs / Sensors won't go in one way, turn the part over. 
// - The holes for the LEDs / Sensors may need a little filing to fit.
// - Leave the paper on the bottom of the plexi for the arm and use that to glue to the disk

function getParameterDefinitions() {
  return [
    { name: 'disk', type: 'float', initial: 77, caption: "disk diameter:" },
    { name: 'hub', type: 'float', initial: 3, caption: "hub diameter:" },
    { name: 'slots', type: 'int', initial: 80, caption: "number of slots:" },
    { name: 'slotd', type: 'float', initial: 11, caption: "slots inset:" },
    { name: 'slotlength', type: 'float', initial: 3.5, caption: "slot length:" },
    { name: 'mask', type: 'float', initial: 0.1, caption: "slot mask adj:" },
    { name: 'cutfudge', type: 'float', initial: 0.4, caption: "laser cut width or<br> (-) filament spread:" },
    { name: 'thick', type: 'float', initial: 3, caption: "material thickness:" },
    { name: 'othick', type: 'float', initial: 0.4, caption: "opaque thickness:" },
{ name: 'output', type: 'choice', caption: 'Output:', values: [0, 1], captions: ["Assembly", "Parts"], initial: 0 }    ];
}

function main () {
var packingEpsilon = 1; //default spacing for flat parts
const M3r = 1.5 //M3 diameter /2
var thick = params.thick
var thin = params.othick
var senser = (3 - params.cutfudge)/2 //size of the sensors LITE-ON LTR-4206E
var emitr = (3 - params.cutfudge)/2 //size of the LED emiters LITE-ON LTE-4206
var slotwidth = Math.PI*params.disk/params.slots/2 - params.cutfudge;
// LED / photodiodes are T3, (3mm) so center to center ~4mm min
//var maskw = params.mask - params.cutfudge
//mask needs to be a circle, not a rectangle
//https://github.com/JamesNewton/HybridDiskEncoder/issues/3
var maskw = slotwidth + params.mask/2 - params.cutfudge
var senseslots = Math.ceil(4.0 / Math.PI*params.disk/params.slots)*2
var sensespace =  senseslots*1.5 //90 degrees out of phase
var slotinc = 360.0/params.slots
var slotd = params.disk - params.slotd //disk diameter less slot inset
var basesize=params.disk+10
var edge = (basesize-params.disk)/2
var supsize = basesize/2+params.hub
var slots = []
   for(i=0.0; i<360; i+=slotinc) {
      slots.push(
        rotate([0,0,i], 
          translate([slotd/2,-slotwidth/2,-1], 
            square({size: [params.slotlength,slotwidth]})
            )
          )
        );
   }

var disk = circle({r: params.disk/2-0.5, fn: 50, center: true})
    .subtract(circle({r: params.hub/2, h:2, center: true}))
    .subtract(slots)
var disksup = circle({r: params.disk/6, center: true})
    .subtract(circle({r: params.hub/2, h:2, center: true}))
var base = square({size: [basesize, basesize], center:true})
    .subtract(translate([slotd/2+params.slotlength/2,+sensespace/2,0],circle({r:emitr, center:true})))
    .subtract(translate([slotd/2+params.slotlength/2,-sensespace/2,0],circle({r:emitr, center:true})))
    .subtract(translate([basesize/2-3,+sensespace/2,0],circle({r: M3r, center:true})))
    .subtract(translate([basesize/2-3,-sensespace/2,0],circle({r: M3r, center:true})))
    .subtract(circle({r: params.hub/2, center: true}))
var washer = circle({r:(sensespace+6)/2, center: true})
    .subtract(circle({r:params.hub/2, h:2, center: true}));
var washertop = washer.translate([0,0,0]) //translate hack copys the object
//var mask = square({size:[slotd-basesize,sensespace+6], center:true})
//    .subtract(translate([params.slotlength/2,+sensespace/2,0],rotate([0,0,+slotinc],square({size: [params.slotlength,maskw], center:true}))))
//    .subtract(translate([params.slotlength/2,-sensespace/2,0],rotate([0,0,-slotinc],square({size: [params.slotlength,maskw], center:true}))))
//    .subtract(translate([-(slotd-basesize)/2-3,+sensespace/2,0],circle({r: M3r, center:true})))
//    .subtract(translate([-(slotd-basesize)/2-3,-sensespace/2,0],circle({r: M3r, center:true})))
var mask = square({size:[slotd-basesize,sensespace+6], center:true})
    .subtract(translate([params.slotlength/2,+sensespace/2,0],rotate([0,0,+slotinc],circle({r: maskw, center:true}))))
    .subtract(translate([params.slotlength/2,-sensespace/2,0],rotate([0,0,-slotinc],circle({r: maskw, center:true}))))
    .subtract(translate([-(slotd-basesize)/2-3,+sensespace/2,0],circle({r: M3r, center:true})))
    .subtract(translate([-(slotd-basesize)/2-3,-sensespace/2,0],circle({r: M3r, center:true})))
var riser = square({size:[edge,sensespace+6], center:true})
    .subtract(translate([-0.5,+sensespace/2,0],circle({r: M3r, center:true})))
    .subtract(translate([-0.5,-sensespace/2,0],circle({r: M3r, center:true})))
var arm = square({size: [slotd,sensespace+6], center:true})
    .union(circle({r:(sensespace+6)/2, center: true}).translate([slotd/2-params.hub,0]))
    .subtract(circle({r: 1, center: true}).translate([-slotd/3,0]))
    .subtract(circle({r: params.hub/2, center: true}).translate([slotd/2-params.hub,0]))
    .translate([-slotd/2+params.hub,0])
var sensors = square({size:[slotd-basesize,sensespace+6], center:true})
    .subtract(translate([params.slotlength/2,+sensespace/2,0],circle({r: senser, center:true})))
    .subtract(translate([params.slotlength/2,-sensespace/2,0],circle({r: senser, center:true})))
    .subtract(translate([-(slotd-basesize)/2-3,+sensespace/2,0],circle({r: M3r, center:true})))
    .subtract(translate([-(slotd-basesize)/2-3,-sensespace/2,0],circle({r: M3r, center:true})))
var LEDs = sensors.translate([0,0,0]) //translate to copy the object
var support = square({size: [supsize,sensespace+6], center:true})
    .subtract(circle({r: params.hub/2, center: true}).translate([-(basesize/2+params.hub)/2+params.hub,0]))
    .subtract(translate([supsize/2-edge/2-0.5,+sensespace/2,0],circle({r: M3r, center:true})))
    .subtract(translate([supsize/2-edge/2-0.5,-sensespace/2,0],circle({r: M3r, center:true})))
    .subtract(circle({r: senser*1.4, center:true}).translate([supsize/2-edge-params.slotd/2+params.slotlength/2,+sensespace/2,0]))
    .subtract(circle({r: senser*1.4, center:true}).translate([supsize/2-edge-params.slotd/2+params.slotlength/2,-sensespace/2,0]))
    .translate([supsize/2-params.hub,0])
    
var assembly = [
    linear_extrude({height: thick},base).setColor(1,0.5,0.3),
    
    linear_extrude({height: thin},washer).translate([0,0,thick]),
    linear_extrude({height: thin},disksup).translate([0,0,thick+thin]).setColor([.2,.2,.2]),
    linear_extrude({height: thin},disk).translate([0,0,thick+thin*2]).setColor([.2,.2,.2]),
    linear_extrude({height: thick},arm).translate([0,0,thick+thin*3]).setColor(1,0.5,0.3),
    linear_extrude({height: thin},washertop).translate([0,0,thick*2+thin*3]),

    linear_extrude({height: thick},LEDs).translate([slotd/2,0,-thick]).setColor(1,0.5,0.3), //below the base

    linear_extrude({height: thin*3},riser).translate([basesize/2-edge/2,0,thick]),
    linear_extrude({height: thin},mask).translate([slotd/2,0,thick+thin*3]).setColor([.2,.2,.2]),
    linear_extrude({height: thick},sensors).translate([slotd/2,0,thick+thin*4]).setColor(1,0.5,0.3),
    linear_extrude({height: thick},support).translate([0,0,thick*2+thin*4]).setColor(1,0.5,0.3),
    ]
    
var cutthick = []
    cutthick.push(base)
    cutthick.push(arm.rotateZ(90))
    cutthick.push(support)
    cutthick.push(sensors) 
    cutthick.push(LEDs) 

//these should be in a separate cut.
var cutthin = []
    cutthin.push(disk)
    cutthin.push(disksup)
    cutthin.push(mask)
    cutthin.push(washer)
    cutthin.push(washertop)
    cutthin.push(riser) //need 2 of these...
    cutthin.push(riser.translate([0,0,0])) //translate to copy the object
    //actually may need three since card stock compresses
    cutthin.push(riser.translate([0,0,0])) //translate to copy the object

if (0 == params.output) out = assembly; 
else { 
    let out1 = binPack(cutthin, packingEpsilon )
    let out2 = binPack(cutthick, packingEpsilon )
    let x = out1.getBounds()[1].x
    //alert(x)
    out = out1.union( out2.translate([0, -x, 0])
            )
        .translate([-basesize, 10, 0]); 
    }
return out;
}

function binPack(pieces2D, packingEpsilon ) {
    // add .w and .h to each piece based on bounds + spacing
    for (var i = 0; i < pieces2D.length; i++) {
        var bounds = pieces2D[i].getBounds();
        pieces2D[i].w = bounds[1].x - bounds[0].x + packingEpsilon;
        pieces2D[i].h = bounds[1].y - bounds[0].y + packingEpsilon;
        }
    //sort by largest dimension
    // https://github.com/jakesgordon/bin-packing/pull/3/commits/a9c72459a968f2be622917f0e05e3dfbeb919720
    pieces2D.sort(function(a,b) { return (max(b.w, b.h) - max(a.w, a.h)); });
    //pack
    var packer = new GrowingPacker();
    packer.fit(pieces2D);
    //check, output
    var out = []
    for (var i = 0; i < pieces2D.length; ++i) {
        var p2D = pieces2D[i];
        if (!p2D.fit) {
            die("Couldn't fit: " + JSON.stringify(p2D));
            }
        var b = p2D.getBounds();
        out.push(p2D.translate([p2D.fit.x - b[0].x, p2D.fit.y - b[0].y, 0]));
        }
    return union(out)
    }

//////////////////////////////////////////////////////////////////////
// start include('packer.growing.js');
// Ami NOTE: grabbed from https://github.com/jakesgordon/bin-packing/blob/master/js/packer.growing.js on 20160803 (not modified since 2011)

/******************************************************************************

This is a binary tree based bin packing algorithm that is more complex than
the simple Packer (packer.js). Instead of starting off with a fixed width and
height, it starts with the width and height of the first block passed and then
grows as necessary to accomodate each subsequent block. As it grows it attempts
to maintain a roughly square ratio by making 'smart' choices about whether to
grow right or down.

When growing, the algorithm can only grow to the right OR down. Therefore, if
the new block is BOTH wider and taller than the current target then it will be
rejected. This makes it very important to initialize with a sensible starting
width and height. If you are providing sorted input (largest first) then this
will not be an issue.

A potential way to solve this limitation would be to allow growth in BOTH
directions at once, but this requires maintaining a more complex tree
with 3 children (down, right and center) and that complexity can be avoided
by simply chosing a sensible starting block.

Best results occur when the input blocks are sorted by height, or even better
when sorted by max(width,height).

Inputs:
------

  blocks: array of any objects that have .w and .h attributes

Outputs:
-------

  marks each block that fits with a .fit attribute pointing to a
  node with .x and .y coordinates

Example:
-------

  var blocks = [
    { w: 100, h: 100 },
    { w: 100, h: 100 },
    { w:  80, h:  80 },
    { w:  80, h:  80 },
    etc
    etc
  ];

  var packer = new GrowingPacker();
  packer.fit(blocks);

  for(var n = 0 ; n < blocks.length ; n++) {
    var block = blocks[n];
    if (block.fit) {
      Draw(block.fit.x, block.fit.y, block.w, block.h);
    }
  }


******************************************************************************/

GrowingPacker = function() { };

GrowingPacker.prototype = {

  fit: function(blocks) {
    var n, node, block, len = blocks.length;
    var w = len > 0 ? blocks[0].w : 0;
    var h = len > 0 ? blocks[0].h : 0;
    this.root = { x: 0, y: 0, w: w, h: h };
    for (n = 0; n < len ; n++) {
      block = blocks[n];
      if (node = this.findNode(this.root, block.w, block.h))
        block.fit = this.splitNode(node, block.w, block.h);
      else
        block.fit = this.growNode(block.w, block.h);
    }
  },

  findNode: function(root, w, h) {
    if (root.used)
      return this.findNode(root.right, w, h) || this.findNode(root.down, w, h);
    else if ((w <= root.w) && (h <= root.h))
      return root;
    else
      return null;
  },

  splitNode: function(node, w, h) {
    node.used = true;
    node.down  = { x: node.x,     y: node.y + h, w: node.w,     h: node.h - h };
    node.right = { x: node.x + w, y: node.y,     w: node.w - w, h: h          };
    return node;
  },

  growNode: function(w, h) {
    var canGrowDown  = (w <= this.root.w);
    var canGrowRight = (h <= this.root.h);

    var shouldGrowRight = canGrowRight && (this.root.h >= (this.root.w + w)); // attempt to keep square-ish by growing right when height is much greater than width
    var shouldGrowDown  = canGrowDown  && (this.root.w >= (this.root.h + h)); // attempt to keep square-ish by growing down  when width  is much greater than height

    if (shouldGrowRight)
      return this.growRight(w, h);
    else if (shouldGrowDown)
      return this.growDown(w, h);
    else if (canGrowRight)
     return this.growRight(w, h);
    else if (canGrowDown)
      return this.growDown(w, h);
    else
      return null; // need to ensure sensible root starting size to avoid this happening
  },

  growRight: function(w, h) {
    this.root = {
      used: true,
      x: 0,
      y: 0,
      w: this.root.w + w,
      h: this.root.h,
      down: this.root,
      right: { x: this.root.w, y: 0, w: w, h: this.root.h }
    };
    if (node = this.findNode(this.root, w, h))
      return this.splitNode(node, w, h);
    else
      return null;
  },

  growDown: function(w, h) {
    this.root = {
      used: true,
      x: 0,
      y: 0,
      w: this.root.w,
      h: this.root.h + h,
      down:  { x: 0, y: this.root.h, w: this.root.w, h: h },
      right: this.root
    };
    if (node = this.findNode(this.root, w, h))
      return this.splitNode(node, w, h);
    else
      return null;
  }

}

// end include('packer.growing.js');


die = function(msg) {
    throw "error: " + msg;
}
