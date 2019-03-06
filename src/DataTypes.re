type city = {
  id: int,
  name: string
};

type cities = list(city);

type model = {
  id: int,
  name: string,
  city: string,
};

type models = list(model);
