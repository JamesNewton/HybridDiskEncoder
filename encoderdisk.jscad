// title      : OpenJSCAD.org encoder disk
// author     : James Newton
// license    : MIT License
// revision   : 0
// tags       : https://github.com/JamesNewton/HybridDiskEncoder
// file       : encoderdisk.jscad
// https://openjscad.com/#https://raw.githubusercontent.com/JamesNewton/HybridDiskEncoder/master/encoderdisk.jscad
// (if that doesn't load, open the site first, then copy in this file)

//NOTES: 
// - The small parts, e.g. riser and washer, can be blown away by the laser cutter. Best to cut the inside holes at full power
//   and the outer parts at reduced power. Or to post edit the vectors to break the outer lines and leave tabs to hold them in.
// - Lasers alway cut with a bit of an angle. If the LEDs / Sensors won't go in one way, turn the part over. 
// - The holes for the LEDs / Sensors may need a little filing to fit.
// - Leave the paper on the bottom of the plexi for the arm and use that to glue to the disk


function getParameterDefinitions() {
  return [
    { name: 'slots', type: 'choice', caption: "Code:", values: [ 
// "start"|sequence|distance|positions
"0000001|\
5,4,3,2,1,2,5,0,1,6,2,3,1,0,1,5,4,2,\
4,3,2,1,0,1,4,6,0,5,1,2,0,6,0,4,3,1,\
3,2,1,0,6,0,3,5,6,4,0,1,6,5,6,3,2,0,\
2,1,0,6,5,6,2,4,5,3,6,0,5,4,5,2,1,6,\
1,0,6,5,4,5,1,3,4,2,5,6,4,3,4,1,0,5,\
0,6,5,4,3,4,0,2,3,1,4,5,3,2,3,0,6,4,\
6,5,4,3,2,3,6,1,2,0,3,4,2,1,2,6,5|18|126",
"01010001|\
7,6,7,1,5,4,5,2,1,4,1,7,0,3,7,\
6,5,6,0,4,3,4,1,0,3,0,6,7,2,6,\
5,4,5,7,3,2,3,0,7,2,7,5,6,1,5,\
4,3,4,6,2,1,2,7,6,1,6,4,5,0,4,\
3,2,3,5,1,0,1,6,5,0,5,3,4,7,3,\
2,1,2,4,0,7,0,5,4,7,4,2,3,6,2,\
1,0,1,3,7,6,7,4,3,6,3,1,2,5,1,\
0,7,0,2,6,5,6,3,2,5,2,0,1,4,0,\
7,6,7,1,5,4,5,2,1,4,1,7,0,3,7,\
6,5,6,0,4,3,4,1,0,3,0,6,7,2,6,\
5,4,5,7,3,2,3,0,7,2,7,5,6,1,5,\
4,3,4,6,2,1,2,7,6,1,6,4,5,0,4,\
3,2,3,5,1,0,1,6,5,0,5,3,4,7,3,\
2,1,2,4,0,7,0,5,4,7,4,2,3,6,2,\
1,0,1,3,7,6,7,4,3,6,3,1,2,5,1,\
0,7,0,2,6,5,6,3,2,5,2,0,1,4|15|240",
"0001111111|\
0,1,0,4,1,6,4,7,4,6,4,8,4,6,4,7,4,6,\
4,9,4,6,4,7,4,6,4,8,4,6,4,7,4,6,4,2,\
9,0,9,3,0,5,3,6,3,5,3,7,3,5,3,6,3,5,\
3,8,3,5,3,6,3,5,3,7,3,5,3,6,3,5,3,1,\
8,9,8,2,9,4,2,5,2,4,2,6,2,4,2,5,2,4,\
2,7,2,4,2,5,2,4,2,6,2,4,2,5,2,4,2,0,\
7,8,7,1,8,3,1,4,1,3,1,5,1,3,1,4,1,3,\
1,6,1,3,1,4,1,3,1,5,1,3,1,4,1,3,1,9,\
6,7,6,0,7,2,0,3,0,2,0,4,0,2,0,3,0,2,\
0,5,0,2,0,3,0,2,0,4,0,2,0,3,0,2,0,8,\
5,6,5,9,6,1,9,2,9,1,9,3,9,1,9,2,9,1,\
9,4,9,1,9,2,9,1,9,3,9,1,9,2,9,1,9,7,\
4,5,4,8,5,0,8,1,8,0,8,2,8,0,8,1,8,0,\
8,3,8,0,8,1,8,0,8,2,8,0,8,1,8,0,8,6,\
3,4,3,7,4,9,7,0,7,9,7,1,7,9,7,0,7,9,\
7,2,7,9,7,0,7,9,7,1,7,9,7,0,7,9,7,5,\
2,3,2,6,3,8,6,9,6,8,6,0,6,8,6,9,6,8,\
6,1,6,8,6,9,6,8,6,0,6,8,6,9,6,8,6,4,\
1,2,1,5,2,7,5,8,5,7,5,9,5,7,5,8,5,7,\
5,0,5,7,5,8,5,7,5,9,5,7,5,8,5,7,5,3|36|360",
"000000|\
4,2,4,5,2,3,1,3,4,1,2,0,2,3,0,1,5,1,2,5,\
0,4,0,1,4,5,3,5,0,3,4,2,4,5,2,3,1,3,4,1,\
2,0,2,3,0,1,5,1,2,5,0,4,0,1,4,5,3,5,0|5|60",
"00001|3,0,1,4,1,0,2,4,0,3,0,4,1,3,4,2,4,3,0,2,3,1,3,2,4,1,2,0,2,1|6|31",
"00001|3,1,0,1,4,0,2,0,4,0,3,4,1,4,3,4,2,3,0,3,2,3,1,2,4,2,1,2,0|6|30",
"110100|1,2,3,5,0,1,2,4,5,0,1,3,4,5,0,2,3,4,5,1,2,3,4,0|4|25",
"11110|3,4,2,3,1,2,0,1,4,0|2|11",
"1110|2,3,1,2,0,1,3,0|2|9"
],
captions:[
    "7,126 IEEE 42 #5 app",
    "8,240 IEEE 42 #5 app",
    "10,360 IEEE 42 #5 app",
    "6,60 IEEE 42 #5 app",
    "5,31 IEEE 42 #5 III",
    "5,30 yoctopuce.com", //yoctopuce.com/EN/article/how-to-measure-wind-part-2"
    "6,25 winzurf.co.nz", //http://www.winzurf.co.nz/Single_Track_Grey_Code_Patent/Single_track_Grey_code_encoder_patent.pdf
    "5,11 winzurf.co.nz", //http://www.winzurf.co.nz/Single_Track_Grey_Code_Patent/Single_track_Grey_code_encoder_patent.pdf
    "4,9 winzurf.co.nz", //http://www.winzurf.co.nz/Single_Track_Grey_Code_Patent/Single_track_Grey_code_encoder_patent.pdf
    ]},
    { name: 'disk', type: 'float', initial: 86, caption: "disk diameter:" },
    { name: 'hub', type: 'float', initial: 3, caption: "hub diameter:" },
    { name: 'slotd', type: 'float', initial: 9, caption: "slots inset:" },
    { name: 'slotlength', type: 'float', initial: 3, caption: "slot length:" },
    { name: 'slotfudge', type: 'float', initial: .05, caption: "slot break:" },
    { name: 'mask', type: 'float', initial: 0.2, caption: "slot mask adj:" },
    { name: 'cutfudge', type: 'float', initial: 0.4, caption: "laser cut width or<br> (-) filament spread:" },
    { name: 'thick', type: 'float', initial: 3, caption: "material thickness:" },
    { name: 'othick', type: 'float', initial: 0.4, caption: "opaque thickness:" },
{ name: 'output', type: 'choice', caption: 'Output:', values: [0, 1], captions: ["Assembly", "Parts"], initial: 0 }    ];
}


//p is starting keyword as a string of binary digits. e.g. "1110"
//s is the sequence as an arraw
//d distance between sensors
function stgc(s, p, d) {
    let l=p.length; //number of sensors
    if (isNaN(d)) {
        dh=Math.ceil(s.length/w.value.length);
        d=1;
    }
    else {
        dh=d;
    }
    let fail=1;
    let v,b=0;
    let m=[]; 
    for(;d<=dh && (fail>0);d++) {
        console.log('length:'+l+' reading:position '+p+':0')
        for(let i=0;i<=s.length*l;i++) { 
            m[i]='_';
        }
        fail=0;
        for(var i=0;i<s.length;i++) {
            for (var j=0;j<l;j++){
                v=j*(d)+i;
                b=p.substr(j,1);
                if (m[v]!='_' && m[v]!=b) {
                        m[v]='x';
                        if (v<s.length*l) {
                            fail=v+1;
                            i=s.length;
                            console.log('length:'+d+' fails at:'+fail);
                        }
                } 
                else {
                    m[v]=b;
                    
                }
            }
        v=parseInt(s[i]);
        b=p.substr(v,1);
        p=p.substring(0,v)+(b=='0'?'1':'0')+p.substr(v+1,9);
        }
    }
    console.log('fail is:'+fail);
    if (fail>0) {
        alert('Fails at '+(fail-1));
    }
    console.log(m)
    return m
}


function cutarc(r, a, i) {
    let curvedpath = CSG.Path2D.arc({
        center: [0,0,0],
        radius: r,
        startangle: a * i - (a/2) + params.slotfudge,
        endangle: a * i + (a/2),
        resolution: resolution,
    });
    let curvedpathin = CSG.Path2D.arc({
        center: [0,0,0],
        radius: r-params.slotlength,
        endangle: a * i - (a/2),
        startangle: a * i + (a/2) - params.slotfudge,
        resolution: resolution,
    });
    let curvedpath2 = curvedpath.concat(curvedpathin)
    let curvedpathclosed = curvedpath2.close()
    let curvedarea = curvedpathclosed.innerToCAG()
    let curvedvolumn = curvedarea //No, need depth
//        let curvedvolumn = curvedpath.rectangularExtrude(
//            params.slotlength, params.thick, resolution, false
//            );  No, because it extends the arc. 
//          expandToCAG(pathradius, resolution) No, same issue
//        let curvedvolumn = curvedarea.linear_extrude({depth:10})
//    let curvedvolumn = curvedarea.extrude({offset: [0, 0,  params.thick]})
    return curvedvolumn
    
}

function cutarcs(positions, r) {
    let a = 360/positions //angle length of each arc
    console.log(positions+" slots of "+a+" degrees")
    curves = []
    for (let i = 0; i<positions; i+=2){
        curves.push(cutarc(r,a,i))
        
    }
    return curves
}

function cutstgcarcs(l, m, r, off) {
    let a = 360/l //angle length of each arc
    console.log(l+" segments of "+a+" degrees")
    curves = []
    for (let i = 0; i<l; i++){
        if ("0"==m[i]) continue
        curves.push(rotate([0,0,off], cutarc(r,a,i)))
        
    }
    return curves
}

var resolution = 8

function eyemask(w) {
    //let w = 3
    let jw = { points: [], color: 'black', type: 'poly' };
    jw.segments = 16
    for (let i = 0; i < Math.PI * 2; i += Math.PI / jw.segments) {
      let x = i >= Math.PI ? Math.PI * 2 - i : i; //over to the right, then back
      x -= Math.PI/2; //recenter
      x /= Math.PI; //scale to the size of the circle
      jw.points.push([w*(Math.sin(i) + 0.0001) / 2, w*x]);
    }
    jw.points.push(jw.points[0]); //close the path
    let path = new CSG.Polygon2D(jw.points)
    return path;//linear_extrude({ height: 1 }, path);
}

function main () {
var packingEpsilon = 1; //default spacing for flat parts
const M3r = 1.5 //M3 diameter /2
console.log(params.slots)
let code=params.slots.split("|")
let start_key = code[0]
let seq = code[1].split(",")
let distance = parseInt(code[2])
let positions = parseInt(code[3])
let distancedeg = 360.0/positions * distance

let m = stgc(seq, start_key, distance)

var thick = params.thick
var thin = params.othick
var senser = (3 - params.cutfudge)/2 //size of the sensors LITE-ON LTR-4206E
var emitr = (3 - params.cutfudge)/2 //size of the LED emiters LITE-ON LTE-4206
var slotwidth = Math.PI*params.disk/positions/2 - params.cutfudge;
// LED / photodiodes are T3, (3mm) so center to center ~4mm min
//var maskw = params.mask - params.cutfudge
//mask needs to be a circle, not a rectangle
//https://github.com/JamesNewton/HybridDiskEncoder/issues/3
var maskw = slotwidth + params.mask/2 - params.cutfudge
var senseslots = Math.ceil(4.0 / Math.PI*params.disk/positions)*2
var sensespace =  senseslots*1.5+senser //90 degrees out of phase
var slotinc = 360.0/positions
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
let stgcoff = distancedeg/2 //offset to avoid LEDs (support)
let stgcr = params.disk/2-params.slotd+params.slotlength
var stgcslots = cutstgcarcs(seq.length, m, stgcr, stgcoff);
// the sensor for the single track grey code. Trying OPB702
// https://www.mouser.com/datasheet/2/414/OPB702-3241541.pdf
var stgcsens = square({size:[4.78, 12.2], center: true})
var washer = circle({r: params.disk/6, center: true})
    .subtract(circle({r: params.hub/2, h:2, center: true}))
var disksup = circle({r:(params.disk-params.slotd)/2, center: true})
    .subtract(circle({r:params.hub/2, h:2, center: true}))
    .subtract(stgcslots);
var disk = circle({r: params.disk/2-0.5, fn: 50, center: true})
    .subtract(circle({r: params.hub/2, h:2, center: true}))
    .subtract(slots)
var washtop = circle({r:(sensespace+6)/2, center: true})
    .subtract(circle({r:params.hub/2, h:2, center: true}));
let stgcsensors = []
   for(i=0.0; i<360; i+=distancedeg) {
      stgcsensors.push(
        rotate([0,0,i+stgcoff], 
          translate([stgcr-(params.slotlength/2),-slotwidth/2,-1], 
            stgcsens//circle({r: senser, center:true})
            )
          )
        );
   }
let maskl = slotd-basesize
var base = square({size: [basesize, basesize], center:true})
    .subtract(translate([slotd/2+params.slotlength/2,+sensespace/2,0],circle({r:emitr, center:true})))
    .subtract(translate([slotd/2+params.slotlength/2,-sensespace/2,0],circle({r:emitr, center:true})))
    .subtract(translate([basesize/2-3,+sensespace/2,0],circle({r: M3r, center:true})))
    .subtract(translate([basesize/2-3,-sensespace/2,0],circle({r: M3r, center:true})))
    .subtract(circle({r: params.hub/2, center: true}))
    .subtract(stgcsensors)
//var mask = square({size:[slotd-basesize,sensespace+6], center:true})
//    .subtract(translate([params.slotlength/2,+sensespace/2,0],rotate([0,0,+slotinc],square({size: [params.slotlength,maskw], center:true}))))
//    .subtract(translate([params.slotlength/2,-sensespace/2,0],rotate([0,0,-slotinc],square({size: [params.slotlength,maskw], center:true}))))
//    .subtract(translate([-(slotd-basesize)/2-3,+sensespace/2,0],circle({r: M3r, center:true})))
//    .subtract(translate([-(slotd-basesize)/2-3,-sensespace/2,0],circle({r: M3r, center:true})))
var mask = square({size:[maskl,sensespace+6], center:true})
    .subtract(translate([params.slotlength/2,+sensespace/2,0],rotate([0,0,+slotinc],eyemask(maskw*2))))
    .subtract(translate([params.slotlength/2,-sensespace/2,0],rotate([0,0,-slotinc],eyemask(maskw*2))))
    .subtract(translate([-(slotd-basesize)/2-3,+sensespace/2,0],circle({r: M3r, center:true})))
    .subtract(translate([-(slotd-basesize)/2-3,-sensespace/2,0],circle({r: M3r, center:true})))
var riser = square({size:[edge,Math.max(sensespace+7,params.hub+4)], center:true})
    .subtract(translate([-0.5,+sensespace/2,0],circle({r: M3r, center:true})))
    .subtract(translate([-0.5,-sensespace/2,0],circle({r: M3r, center:true})))
var arm = square({size: [slotd,Math.max(sensespace+7,params.hub+4)], center:true})
    .union(circle({r:(sensespace+6)/2, center: true}).translate([slotd/2-params.hub,0]))
    .subtract(circle({r: 1, center: true}).translate([-slotd/3,0]))
    .subtract(circle({r: params.hub/2, center: true}).translate([slotd/2-params.hub,0]))
    .translate([-slotd/2+params.hub,0])
var sensors = square({size:[maskl,sensespace+6], center:true})
    .subtract(translate([params.slotlength/2,+sensespace/2,0],circle({r: senser, center:true})))
    .subtract(translate([params.slotlength/2,-sensespace/2,0],circle({r: senser, center:true})))
    .subtract(translate([-(slotd-basesize)/2-3,+sensespace/2,0],circle({r: M3r, center:true})))
    .subtract(translate([-(slotd-basesize)/2-3,-sensespace/2,0],circle({r: M3r, center:true})))
var LEDs = sensors.translate([0,0,0]) //translate to copy the object
var support = square({size: [supsize,Math.max(sensespace+7,params.hub+4)], center:true})
    .subtract(circle({r: params.hub/2, center: true}).translate([-(basesize/2+params.hub)/2+params.hub,0]))
    .subtract(translate([supsize/2-edge/2-0.5,+sensespace/2,0],circle({r: M3r, center:true})))
    .subtract(translate([supsize/2-edge/2-0.5,-sensespace/2,0],circle({r: M3r, center:true})))
    .subtract(circle({r: senser*1.4, center:true}).translate([supsize/2-edge-params.slotd/2+params.slotlength/2,+sensespace/2,0]))
    .subtract(circle({r: senser*1.4, center:true}).translate([supsize/2-edge-params.slotd/2+params.slotlength/2,-sensespace/2,0]))
    .translate([supsize/2-params.hub,0])
    
var assembly = [
    linear_extrude({height: thick}, base    ).translate([0,0,-0.05]).setColor(1,0.5,0.3,1),
    linear_extrude({height: thin},  washer  ).translate([0,0,thick]).setColor([.2,.2,.2]),
    linear_extrude({height: thin},  disksup ).translate([0,0,thick+thin]).setColor([1,1,1]),
    linear_extrude({height: thin},  disk    ).translate([0,0,thick+thin*2]).setColor([.2,.2,.2]),
    linear_extrude({height: thick}, arm     ).translate([0,0,thick+thin*3]).setColor(1,0.5,0.3),
    linear_extrude({height: thin},  washtop ).translate([0,0,thick*2+thin*3]).setColor([.2,.2,.2]),
    linear_extrude({height: thick}, LEDs    ).translate([slotd/2,0,-thick]).setColor(1,0.5,0.3), //below the base
    linear_extrude({height: thin*3},riser   ).translate([basesize/2-edge/2,0,thick]),
    linear_extrude({height: thin},  mask    ).translate([slotd/2,0,thick+thin*3]).setColor([.2,.2,.2]),
    linear_extrude({height: thick}, sensors ).translate([slotd/2,0,thick+thin*4]).setColor(1,0.5,0.3),
    linear_extrude({height: thick}, support ).translate([0,0,thick*2+thin*4]).setColor(1,0.5,0.3),
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
    cutthin.push(washtop)
    cutthin.push(riser) //need 2 of these...
    cutthin.push(riser.translate([0,0,0])) //translate to copy the object
    //actually may need three since card stock compresses
    cutthin.push(riser.translate([0,0,0])) //translate to copy the object

if (0 == params.output) out = assembly; 
else { 
    let out1 = binPack(cutthin, packingEpsilon )
    let out2 = binPack(cutthick, packingEpsilon )
    let b = out2.getBounds()[1]
    let x = b.x+2
    let y = b.y/2
    //alert(x)
    out = out2.union( out1.translate([0, x, 0])
            )
        .translate([-y, -x, 0]); 
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
