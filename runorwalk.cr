class Drop 
	property x : Float64, y : Float64, floor, wet
	def initialize(@x,@y,@floor = @wet = false) end
  end
def ammount_drops (walk_speed)
	rain_speed=9.0 #meters per second	
	adms=500 # ammount of drops per meter per second
	person_depth=0.35
	person_height=1.7
	x=-4.0
	xfinal=30.0+person_depth/2
	dt=0.01
	drops=[] of Drop
	how_wet=0
	while x<=xfinal
		(dt*adms*xfinal).to_i.times{
			drops<<Drop.new(Random.rand()*xfinal,2.5) #random horizontal pos, 2.5m high
		}
		drops.each{|d|
			d.y-=rain_speed*dt
			d.floor = true if d.y<=0
			d.wet = true if d.y>0 && d.y<person_height && d.x>x-person_depth && d.x<x+person_depth
		}
		how_wet+=drops.select{|d| d.wet}.size
		drops.select!{|d| !d.floor && !d.wet}
		x+=walk_speed*dt
	end

	return "#{how_wet/adms.to_f}"
end

puts "Walk on rain wetness = " +ammount_drops(1.4)
puts " Run on rain wetness = " +ammount_drops(5.0)

