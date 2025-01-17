//Flange to hold encoder disk onto threaded shaft. 

function main() {
    fudge = 0.4 //mm of fudge factor
	hi = 10;
	dia = 20;
	fldi = 40;
	flhi = 5
	tab = 3
	nut = difference(
		cylinder({r:dia*0.7, h:hi, fn:6}),
		cylinder({r:dia/2+fudge, h:hi + 0.2}).translate([0,0,-0.1])
	);
	threads = thread_in_pitch(dia+fudge,hi-0.0, 1.8)
	    .translate([0,0,0.1]);
	flange = difference(
	    union(
		cylinder({r:fldi/2, h:flhi/2, fn:20}),
		cylinder({r1:fldi/2, r2:dia/2+fudge, h:flhi/2, fn:20})
		    .translate([0,0,flhi/2])
		),
		cylinder({r:dia/2+fudge, h:hi + 0.2}).translate([0,0,-0.1]),
		cylinder({r:tab/2+fudge, h:hi + 0.2})
		    .translate([((fldi-dia)*.7+dia)/2,0,-0.1]),
		cylinder({r:tab/2+fudge, h:hi + 0.2})
		    .translate([-((fldi-dia)*.7+dia)/2,0,-0.1])
	);

  return union(nut, threads, flange);
}

//insert iso_threads.jscad from
//https://www.thingiverse.com/thing:2307544
