Property::Property()
{
    m_type = Type::NoInit;
}

Property::~Property()
{
	if (m_type == Type::String)
		delete string_data;
}

Property::Property(const Property& property)
{
	m_type = property.m_type;
	switch (m_type)
	{
		case(Type::Float):
		{
			float_data = property.float_data;
			break;
		}
		case(Type::Int):
		{
			int_data = property.int_data;
			break;
		}
		case(Type::Bool):
		{
			bool_data = property.bool_data;
			break;
		}
		case(Type::String):
		{
			string_data = new std::string(*property.string_data);
			break;
		}
		default:break;
	}
}

Property& Property::operator=(const Property& property)
{
	m_type = property.m_type;
	switch (m_type)
	{
		case(Type::Float):
		{
			float_data = property.float_data;
			break;
		}
		case(Type::Int):
		{
			int_data = property.int_data;
			break;
		}
		case(Type::Bool):
		{
			bool_data = property.bool_data;
			break;
		}
		case(Type::String):
		{
			string_data = new std::string(*property.string_data);
			break;
		}
		default:break;
	}
	return *this;
}

Property::Property(Property&& property)
{
	m_type = property.m_type;
	switch (m_type)
	{
	case(Type::Float):
	{
		float_data = property.float_data;
		break;
	}
	case(Type::Int):
	{
		int_data = property.int_data;
		break;
	}
	case(Type::Bool):
	{
		bool_data = property.bool_data;
		break;
	}
	case(Type::String):
	{
		string_data = property.string_data;
		property.string_data = nullptr;
		break;
	}
	default:break;
	}
}

Property& Property::operator=(Property&& property)
{
	m_type = property.m_type;
	switch (m_type)
	{
	case(Type::Float):
	{
		float_data = property.float_data;
		break;
	}
	case(Type::Int):
	{
		int_data = property.int_data;
		break;
	}
	case(Type::Bool):
	{
		bool_data = property.bool_data;
		break;
	}
	case(Type::String):
	{
		string_data = property.string_data;
		property.string_data = nullptr;
		break;
	}
	default:break;
	}
	return *this;
}

Property::Property(bool bool_value)
{
    m_type = Type::Bool;
    bool_data = bool_value;
}

Property::Property(int int_value)
{
    m_type = Type::Int;
    int_data = int_value;
}

Property::Property(const std::string& string_value)
{
    m_type = Type::String;
    string_data = new std::string(string_value);
}

Property::Property(float float_value)
{
    m_type = Type::Float;
    float_data = float_value;
}

bool Property::asBool() const
{
    assert(m_type == Type::Bool);
    return bool_data;
}
int Property::asInt() const
{
    assert(m_type == Type::Int);
    return int_data;
}
float Property::asFloat() const
{
    assert(m_type == Type::Float);
    return float_data;
}
const std::string& Property::asString() const
{
    assert(m_type == Type::String);
    return *string_data;
}
bool Property::isValid() const
{
    return m_type != Type::NoInit;
}

///////////////////////////////////////////////////////////

const Vector& GameObject::getPosition() const
{
    return m_pos;
}

void GameObject::setPosition(const Vector& point)
{
    onPositionChanged(point, m_pos);
    m_pos = point;
}

void GameObject::setPosition(float x, float y)
{
    setPosition(Vector(x, y));
}

void GameObject::move(const Vector& point)
{
    m_pos += point;
}

void GameObject::setSize(const Vector& size)
{
    m_size = size;
}


void GameObject::update(int delta_time)
{
    if (isEnabled())
    {
    }
}

void GameObject::start()
{

}

void GameObject::setName(const std::string& name)
{
    m_name = name;
}

const std::string&  GameObject::getName() const
{
    return m_name;
}

void GameObject::setProperty(const std::string& name, const Property& property)
{
    m_properties[name] = property;
    onPropertySet(name);
};

Property GameObject::getProperty(const std::string& name) const
{
    onPropertyGet(name);
    return const_cast<GameObject*>(this)->m_properties[name];
};

void GameObject::disable()
{
    m_enable = false;
}

void GameObject::enable()
{
    m_enable = true;
}

bool GameObject::isEnabled() const
{
    return m_enable;
}

void GameObject::hide()
{
    m_visible = false;
}

void GameObject::show()
{
    m_visible = true;
}

bool GameObject::isVisible() const
{
    return m_visible;
}

void GameObject::turnOn()
{
    show();
    enable();
}
void GameObject::turnOff()
{
    hide();
    disable();
}


GameObject::~GameObject()
{

}

void GameObject::draw(sf::RenderWindow* window)
{

}


void GameObject::onPropertySet(const std::string& name)
{
    if (name == "x")
        setPosition(m_properties["x"].asFloat(),getPosition().y);
    else if (name == "y")
        setPosition(getPosition().x, m_properties["y"].asFloat());
    else if (name == "name")
        setName(m_properties["name"].asString());

}

void GameObject::onPropertyGet(const std::string& name) const
{

}


void GameObject::clear()
{
    
}

//////////////////////////////////////////////////////