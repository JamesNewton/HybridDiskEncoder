// title      : STGC Encoder Disk
// author     : James Newton
// license    : MIT License
// revision   : 0.003
// tags       : encoder, grey code, single track, STGC
// file       : stgc_wheel.js

function getParameterDefinitions() {
  return [
    { name: 'slots', type: 'choice', caption: "Code:", 
values: [
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
    { name: 'disk', type: 'float', initial: 77, caption: "disk diameter:" },
    { name: 'hub', type: 'float', initial: 3, caption: "hub diameter:" },
    { name: 'slotd', type: 'float', initial: 11, caption: "slots inset:" },
    { name: 'slotlength', type: 'float', initial: 3.5, caption: "slot length:" },
    { name: 'slotfudge', type: 'float', initial: .05, caption: "slot break:" },
    { name: 'mask', type: 'float', initial: 0.1, caption: "slot mask adj:" },
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
    //let curvedvolumn = curvedarea No, need depth
//        let curvedvolumn = curvedpath.rectangularExtrude(
//            params.slotlength, params.thick, resolution, false
//            );  No, because it extends the arc. 
//          expandToCAG(pathradius, resolution) No, same issue
//        let curvedvolumn = curvedarea.linear_extrude({depth:10})
    let curvedvolumn = curvedarea.extrude({offset: [0, 0,  params.thick]})
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

function cutstgcarcs(l, m,r) {
    let a = 360/l //angle length of each arc
    console.log(l+" segments of "+a+" degrees")
    curves = []
    for (let i = 0; i<l; i++){
        if ("0"==m[i]) continue
        curves.push(cutarc(r,a,i))
        
    }
    return curves
}

var resolution = 64

function main () {
    console.log(params.slots)
    let code=params.slots.split("|")
    let start_key = code[0]
    let seq = code[1].split(",")
    let distance = parseInt(code[2])
    let positions = parseInt(code[3])
    let m = stgc(seq, start_key, distance)
    //return union(cutarcs(seq.length, m, params.disk-params.slotd*2))
    return difference(
        cylinder({r:params.disk, h:params.thick})
        ,union(cutstgcarcs(seq.length, m, params.disk-params.slotd*2-params.slotlength))
        ,union(cutarcs(positions, params.disk-params.slotd))
        ,cylinder({r:params.hub, h:params.thick})
        )
//    difference(
//      cylinder({r: 10, h:10}),
//      sphere({r: 2, center: true})
//    ).translate([0, 0, 1.5]).scale(10);
}
