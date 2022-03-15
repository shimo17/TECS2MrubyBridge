# class Shimo
# 	def initialize
#     	@lcd = EV3RT::LCD.new
# 	end
	
# 	def mcall_lcd(number)
# 		@lcd.print number
# 	end

# 	def lcd
# 		@lcd.print "05091997"
# 	end
# end

# class Ryo
# 	def initialize
#     	@lcd = EV3RT::LCD.new
# 	end

# 	def mcall_hyoji(number)
# 		 @lcd.print number
# 	end

# 	def hyoji
# 		@lcd.print "saitama_university"
		
# 	end
# end
#山本さん環境に自分の提案フレームワークを移植したときに動作確認済みのmrubyコード

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


class dynamic
	def dynamic_cange(change)
		if change==1
			con1 = lcd
			return con2
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
	 	 