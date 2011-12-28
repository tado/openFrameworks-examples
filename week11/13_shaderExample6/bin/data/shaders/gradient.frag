varying vec3 normal;
varying vec4 position;

uniform float x;
uniform float y;
uniform float w;
uniform float h;

//uniform float gradientStartPositionX;
//uniform float gradientStartPositionY;
//uniform float gradientLength;
//uniform float gradientNormalizedX;
//uniform float gradientNormalizedY;

uniform vec2  gradientCenter;
uniform vec2  gradientAngle;
uniform float gradientLength;
uniform vec3  gradientColorA;
uniform vec3  gradientColorB;
uniform float gradientAlpha;



void main() {

	

	vec2 pta;
	pta.x		= gradientCenter.x - gradientLength * 0.5 * gradientAngle.x;
	pta.y		= gradientCenter.y - gradientLength * 0.5 * gradientAngle.y;
	vec2 v0		= vec2(position) - pta;
	float t		= dot(v0, gradientAngle);
	t			= clamp(t/gradientLength, 0.0,1.0);
	
	vec3 color = (1.0-t) * gradientColorA + (t) * gradientColorB;
	gl_FragColor = vec4 (color.x, color.y, color.z,gradientAlpha);
}


/*


pc = # the point you are coloring now
p0 = # start point
p1 = # end point
v = p1 - p0
d = Length(v)
v = Normalize(v) # or Scale(v, 1/d)

v0 = pc - p0

t = Dot(v0, v)
t = Clamp(t/d, 0, 1)

color = (start_color * t) + (end_color * (1 - t))

*/


/*	vec2 pta;
	pta.x = x;
	pta.y = y;
	vec2 ptb;
	ptb.x = x+30.0;
	ptb.y = y+30.0;
	vec2 myPosition;
	myPosition.x = position.x;
	myPosition.y = position.y;
	vec2 v = ptb - pta;
	float d = length(v);
	v = normalize(v);
	
	// things I need to pass in, I guess...  v(normalized vector of line) pta(start point) d(length) 

*/