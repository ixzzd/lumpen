type model = {
  id: int,
  name: string,
  city: string,
  position: int
};

type city = {
  id: int,
  name: string,
  position: int
};

type cities = list(city);

type models = list(model);
