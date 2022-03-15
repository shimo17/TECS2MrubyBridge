def lcd
	@lcd = EV3RT::LCD.new
	@lcd.print "05091997"
end

def hyoji
	@lcd = EV3RT::LCD.new
	@lcd.print "saitama_university"	
end

def lcd_hyoji
	@lcd = EV3RT::LCD.new
	@lcd.print "gunma_university"
end

def warning
	@lcd = EV3RT::LCD.new
	@lcd.print "no"
end


class Dynamic
	def dynamic_change(change)
		if change==1
			con1 = lcd
			return con1
		elsif change==2
            con2 = hyoji
            return con2
		elsif change==3
            con3 = lcd_hyoji
            return con3
		else
			con4 = warning
			return con4
		end
    end
end